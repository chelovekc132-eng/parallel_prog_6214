module matrix;

import std;

Matrix::Matrix(std::size_t size)
    : size_(size),
      data_(size * size, 0.0) {}

std::size_t Matrix::size() const noexcept {
    return size_;
}

double& Matrix::operator()(
    std::size_t row,
    std::size_t column
) {
    return data_[row * size_ + column];
}

double Matrix::operator()(
    std::size_t row,
    std::size_t column
) const {
    return data_[row * size_ + column];
}

Matrix Matrix::fromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        throw std::runtime_error(
            "Cannot open file: " + filename
        );
    }

    std::size_t n;

    if (!(file >> n)) {
        throw std::runtime_error(
            "Invalid matrix size"
        );
    }

    Matrix matrix(n);

    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < n; ++j) {
            if (!(file >> matrix(i, j))) {
                throw std::runtime_error(
                    "Invalid matrix data"
                );
            }
        }
    }

    return matrix;
}

void Matrix::toFile(
    const std::string& filename
) const {
    std::ofstream file(filename);

    if (!file) {
        throw std::runtime_error(
            "Cannot create file: " + filename
        );
    }

    file << size_ << '\n';

    for (std::size_t i = 0; i < size_; ++i) {
        for (std::size_t j = 0; j < size_; ++j) {
            file << (*this)(i, j);

            if (j + 1 < size_) {
                file << ' ';
            }
        }

        file << '\n';
    }
}

Matrix Matrix::multiply(
    const Matrix& a,
    const Matrix& b
) {
    if (a.size() != b.size()) {
        throw std::invalid_argument(
            "Matrix sizes must match"
        );
    }

    const std::size_t n = a.size();

    Matrix result(n);

    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t k = 0; k < n; ++k) {
            const double aik = a(i, k);

            for (std::size_t j = 0; j < n; ++j) {
                result(i, j) +=
                    aik * b(k, j);
            }
        }
    }

    return result;
}
