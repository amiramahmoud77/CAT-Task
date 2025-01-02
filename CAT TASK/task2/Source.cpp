#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> operations;  // هنا هنحتفظ بالعمليات

    // إدخال عدد العمليات
    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    // إدخال العمليات
    cout << "Enter the operations (either ++ or --):\n";
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        operations.push_back(op);  // إضافة العملية للقائمة
    }

    // بدأ العدد من 0
    int number = 0;

    // تطبيق العمليات
    for (const string& op : operations) {
        if (op == "++") {
            number++;  // زياده العدد بمقدار 1
        }
        else if (op == "--") {
            number--;  // تقليل العدد بمقدار 1
        }
    }

    // إخراج النتيجة النهائية
    cout << "Final number: " << number << endl;

    return 0;
}



