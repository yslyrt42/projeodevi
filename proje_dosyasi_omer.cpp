// İsim Soyisim: Ömer Yeşilyurt
// Öğrenci No: 25901017
// Proje: Sexy Prime Sayıları

#include <iostream>
#include <vector>

using namespace std;

// Asal sayıları Eratosthenes Eleği ile bulan fonksiyon
vector<bool> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

// Sexy prime çiftlerini ekrana yazdıran fonksiyon
void printSexyPrimes(const vector<bool>& isPrime, int limit) {
    for (int number = 2; number + 6 <= limit; number++) {
        if (isPrime[number] && isPrime[number + 6]) {
            cout << "(" << number << ", " << number + 6 << ")" << endl;
        }
    }
}

int main() {
    const int N = 10000000;

    vector<bool> primeNumbers = generatePrimes(N);

    printSexyPrimes(primeNumbers, N);

    return 0;
}

                                                                    
