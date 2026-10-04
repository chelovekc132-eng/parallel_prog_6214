export module matrix;

import std;

export class Matrix {
private:
    std::sizet size{};
    std::vector<double> data_;

public:
    explicit Matrix(std::size_t size);

    [[nodiscard]]
    std::size_t size() const noexcept;

    double& operator()(std::size_t row, std::size_t column);

    [[nodiscard]]
    double operator()(
        std::size_t row,
        std::size_t column
    ) const;

    [[nodiscard]]
    static Matrix fromFile(const std::string& filename);

    void toFile(const std::string& filename) const;

    [[nodiscard]]
    static Matrix multiply(
        const Matrix& a,
        const Matrix& b
    );
};
