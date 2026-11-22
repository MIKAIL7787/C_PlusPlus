#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество чисел N (от 1 до 100): ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Ошибка! Число N должно быть от 1 до 100." << endl;
        return 0;
    }

    int pos = 0;
    int neg = 0;
    int zero = 0;
    int sum = 0;
    int min_val = 0;
    int max_val = 0;
    int even = 0;
    int odd = 0;

    int prev = 0;
    bool is_sorted = true;
    bool has_repeat = false;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Введите число: ";
        cin >> x;

        if (x > 0) {
            pos++;
        } else if (x < 0) {
            neg++;
        } else {
            zero++;
        }

        sum = sum + x;

        if (i == 0) {
            min_val = x;
            max_val = x;
        } else {
            if (x < min_val) {
                min_val = x;
            }
            if (x > max_val) {
                max_val = x;
            }
            if (x <= prev) {
                is_sorted = false;
            }
            if (x == prev) {
                has_repeat = true;
            }
        }

        if (x % 2 == 0) {
            even++;
        } else {
            odd++;
        }

        prev = x;
    }

    double avg = (double)sum / n;

    cout << endl;
    cout << "===== ОТЧЁТ =====" << endl;
    cout << "Введено чисел: " << n << endl;
    cout << "Положительных: " << pos << endl;
    cout << "Отрицательных: " << neg << endl;
    cout << "Нулей: " << zero << endl;
    cout << "Чётных: " << even << endl;
    cout << "Нечётных: " << odd << endl;
    cout << "Сумма: " << sum << endl;
    cout << "Минимум: " << min_val << endl;
    cout << "Максимум: " << max_val << endl;
    cout << "Среднее: " << fixed << setprecision(2) << avg << endl;

    if (sum % 2 == 0) {
        cout << "Сумма чётная: да" << endl;
    } else {
        cout << "Сумма чётная: нет" << endl;
    }

    if (is_sorted) {
        cout << "По возрастанию: да" << endl;
    } else {
        cout << "По возрастанию: нет" << endl;
    }

    if (has_repeat) {
        cout << "Есть повтор подряд: да" << endl;
    } else {
        cout << "Есть повтор подряд: нет" << endl;
    }
    cout << "=================" << endl;

    return 0;
}
