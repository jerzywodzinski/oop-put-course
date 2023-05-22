#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IntegerSequence {
public:
    virtual vector<int> Numbers() = 0;
};

class Positive : public IntegerSequence {
    vector<int> numVec;

public:
    Positive(vector<int> input) {
        numVec = input;
    }

    vector<int> Numbers() override {
        vector<int> positiveNumbers;
        for (int num : numVec) {
            if (num >= 0)
                positiveNumbers.push_back(num);
        }
        return positiveNumbers;
    }
};

class Even : public IntegerSequence {
    IntegerSequence* IntegerSequenceP;

public:
    Even(IntegerSequence* integerseq) : IntegerSequenceP(integerseq) {}

    vector<int> Numbers() override {
        vector<int> numbers = IntegerSequenceP->Numbers();
        vector<int> evennumbers;
        for (int num : numbers) {
            if (num % 2 == 0)
                evennumbers.push_back(num);
        }
        return evennumbers;
    }
};

class Sorted : public IntegerSequence {
    IntegerSequence* IntegerSequenceP;

public:
    Sorted(IntegerSequence* integerseq) : IntegerSequenceP(integerseq) {}

    vector<int> Numbers() override {
        vector<int> numbers = IntegerSequenceP->Numbers();
        sort(numbers.begin(), numbers.end());
        return numbers;
    }
};

int main() {
    vector<int> y{-2,-4,4,8,9,-5,10,19,20};
    IntegerSequence* IntegerSequenceP = new Even(new Sorted(new Positive(y)));

    vector<int> result = IntegerSequenceP->Numbers();
    for (int i: result){
        cout << i << " ";
    }
    return 0;
}
