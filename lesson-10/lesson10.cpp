#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>

class Nucleotide {
    std::string sequence;
    std::vector<std::thread> threads;
    std::mutex mutex;
    std::atomic<int> quantity[4];

public:
    Nucleotide(const std::string& seq) : sequence(seq) {
        quantity[0] = 0;
        quantity[1] = 0;
        quantity[2] = 0;
        quantity[3] = 0;
    }

    void Count(int start, int end) {
        int quantity1[4] = {0, 0, 0, 0};

        for (int i = start; i < end; i++) {
            char nucleotide = sequence[i];
            if (nucleotide == 'A')
                quantity1[0]++;
            else if (nucleotide == 'C')
                quantity1[1]++;
            else if (nucleotide == 'G')
                quantity1[2]++;
            else if (nucleotide == 'T')
                quantity1[3]++;
        }

        std::lock_guard<std::mutex> lock(mutex);
        quantity[0] += quantity1[0];
        quantity[1] += quantity1[1];
        quantity[2] += quantity1[2];
        quantity[3] += quantity1[3];
    }

    void Start(int threads1) {
        int size = sequence.length() / threads1;
        int start = 0, end = size;

        for (int i = 0; i < threads1 - 1; i++) {
            threads.emplace_back(&Nucleotide::Count, this, start, end);
            start = end;
            end += size;
        }

        threads.emplace_back(&Nucleotide::Count, this, start, sequence.length());

        for (auto& thread : threads) {
            thread.join();
        }
    }

    void show() {
        std::cout << "Frequency:" << std::endl;
        std::cout << "A: " << quantity[0] << std::endl;
        std::cout << "C: " << quantity[1] << std::endl;
        std::cout << "G: " << quantity[2] << std::endl;
        std::cout << "T: " << quantity[3] << std::endl;
    }
};

int main() {

    std::string dna = "ACACGTGTGTGTGTGTACAACACACCCCGCGCACGC";
    int threads1 = std::thread::hardware_concurrency();
    Nucleotide seq1(dna);
    seq1.Start(threads1);
    seq1.show();

    return 0;
}
