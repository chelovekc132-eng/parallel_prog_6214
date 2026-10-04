import std;
import matrix;

int main(int argc, char* argv[]) {
    try {
        if (argc != 4) {
            std::cerr
                << "Usage: matrix_multiplication "
                << "<matrix_a> <matrix_b> <result>\n";

            return 1;
        }

        const Matrix a =
            Matrix::fromFile(argv[1]);

        const Matrix b =
            Matrix::fromFile(argv[2]);

        if (a.size() != b.size()) {
            throw std::invalid_argument(
                "Matrices must have the same size"
            );
        }

        const auto start =
            std::chrono::steady_clock::now();

        const Matrix result =
            Matrix::multiply(a, b);

        const auto finish =
            std::chrono::steady_clock::now();

        const std::chrono::duration<double> elapsed =
            finish - start;

        result.toFile(argv[3]);

        const std::size_t n = a.size();

        const std::uint64_t multiplications =
            static_cast<std::uint64_t>(n) * n * n;

        const std::uint64_t additions =
            static_cast<std::uint64_t>(n) * n * (n - 1);

        const std::uint64_t operations =
            multiplications + additions;

        const double gflops =
            static_cast<double>(operations) /
            elapsed.count() /
            1'000'000'000.0;

        std::cout
            << "Matrix size: "
            << n << " x " << n << '\n';

        std::cout
            << "Multiplications: "
            << multiplications << '\n';

        std::cout
            << "Additions: "
            << additions << '\n';

        std::cout
            << "Total operations: "
            << operations << '\n';

        std::cout
            << "Time: "
            << elapsed.count()
            << " seconds\n";

        std::cout
            << "Performance: "
            << gflops
            << " GFLOPS\n";

    } catch (const std::exception& e) {
        std::cerr
            << "Error: "
            << e.what()
            << '\n';

        return 1;
    }

    return 0;
}
