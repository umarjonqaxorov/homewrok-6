#include <iostream>
#include <string>

using namespace std;
int globalNum;
string mostFrequentString(const string& str1, const string& str2, char character, bool& sameTimes) {
    int countStr1 = 0, countStr2 = 0;
    for (char ch: str1) {
        if (ch == character)
            countStr1++;
    }
    for (char ch : str2) {
        if (ch == character)
            countStr2++;
    }

    if (countStr1 == countStr2) {
        sameTimes = true;
        return "";
    } else {
        sameTimes = false;
        return countStr1 > countStr2 ? str1 : str2;
    }
}
void convertString(string& str, int& numDigits) {
    numDigits = 0;
    for (char& ch : str) {
        if (isdigit(ch)) {
            numDigits++;
        } else if (islower(ch)) {
            ch = toupper(ch);
        } else if (isupper(ch)) {
            ch = tolower(ch);
        }
    }
}
template<typename T>
T maxSumPair(T a, T b, T c) {
    return (a + b > b + c) ? (a + b) : (b + c);
}

template<typename T>
void findMinMax(const T arr[], int size, T& min, T& max) {
    min = max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
}
template<typename T>
T& swapAndReturnLarger(T& a, T& b) {
    if (a > b)
        return a;
    else {
        std::swap(a, b);
        return b;
    }
}

template<typename T, int N>
void swapArrays(T (&arr1)[N], T (&arr2)[N]) {
    for (int i = 0; i < N; ++i) {
        std::swap(arr1[i], arr2[i]);
    }
}
int main() {
    cout<<"Problem_1"<< endl;
    int localNum;
    cout << "Enter globalNum and localNum";
    cin>> localNum>>globalNum;
    int remainder=globalNum%localNum;
    cout<<" Remainder: "<< remainder<< endl;

    cout<< "Problem_2"<< endl;
    string str1, str2;
    char character;

    cout << "Enter two strings separated by space: ";
    cin >> str1 >> str2;

   cout << "Enter a character: ";
   cin >> character;

    bool sameTimes;
    string result = mostFrequentString(str1, str2, character, sameTimes);

    if (result.empty()) {
        if (sameTimes)
            cout << "Same times" << std::endl;
        else
           cout << "Not found" << std::endl;
    } else {
        int count = 0;
        for (char ch : result) {
            if (ch == character)
                count++;
        }
       cout << "The string \"" << result << "\" contains the character '" << character << "' most times (" << count << " times)." << endl;
    }

    cout<< "Problem_3" << endl;
    string input;
    int numDigits;

    do {
        cout << "Enter a string: ";
         cin >> input;

         if (input.back() == 'x') {
             input.pop_back();
             convertString(input, numDigits);
             cout << input << " contains " << numDigits << " digits" << std::endl;
             break;
         } else {
            cout << "String does not end with 'x'. Please try again." << std::endl;
         }
    } while (true);

    cout << "Problem_4" << endl;
    int choice;
    std::cout << "Enter 1 to find the largest sum pair or 2 to find the min and max of an array: ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            int num1, num2, num3;
            cout << "Enter three numeric values: ";
            cin >> num1 >> num2 >> num3;
            cout << "Largest sum pair: " << maxSumPair(num1, num2, num3) << std::endl;
            break;
        }
        case 2: {
            const int size = 7;
            int arr[size];
            cout << "Enter " << size << " numeric values for the array: ";
            for (int i = 0; i < size; ++i)
                std::cin >> arr[i];
            int min, max;
            findMinMax(arr, size, min, max);
            cout << "Min: " << min << " Max: " << max << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice." << std::endl;
    }
    cout <<"Problem_5"<< endl;
    int choice1;
    cout << "Enter 1 to swap and return larger value, or 2 to swap elements of arrays: ";
    cin >> choice1;

    switch (choice) {
        case 1: {
            int num1, num2;
            cout << "Enter two numeric values: ";
            cin >> num1 >> num2;
            int& larger = swapAndReturnLarger(num1, num2);
            cout << "Larger value after swapping: " << larger << std::endl;
            break;
        }
        case 2: {
            const int size = 5; // Assuming the size of the arrays
            int arr1[size], arr2[size];
            cout << "Enter " << size << " numeric values for the first array: ";
            for (int i = 0; i < size; ++i)
               cin >> arr1[i];
            cout << "Enter " << size << " numeric values for the second array: ";
            for (int i = 0; i < size; ++i)
                cin >> arr2[i];
            swapArrays(arr1, arr2);
            cout << "After swapping, first array: ";
            for (int i = 0; i < size; ++i)
                cout << arr1[i] << " ";
              cout << std::endl << "Second array: ";
            for (int i = 0; i < size; ++i)
                cout << arr2[i] << " ";
                cout << std::endl;
            break;
        }
        default:
            cout << "Invalid choice." << std::endl;
    }

    return 0;
}
