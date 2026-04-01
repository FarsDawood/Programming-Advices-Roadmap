<div dir="rtl">

# الفصل الثالث عشر: التعامل مع النصوص (Dealing With Strings)

## 🔡 الدرس الخمسون: الـ String Object وأهم الـ Methods المدمجة

في هذا الدرس، سنتعرف على مجموعة من الـ Methods الجاهزة والمفيدة جداً والموجودة ضمنياً داخل الـ String Object.

هذا الدرس يُعتبر مقدمة بسيطة لمفهوم الـ Object-Oriented Programming (OOP).
الـ string في C++ ليس مجرد Data Type عادي لتخزين النصوص، بل هو Object (كائن). أي أن هذا الـ Object يحتوي بداخله على مجموعة من الـ Methods (والتي هي عبارة عن Functions تابعة له) تسهل علينا التعامل معه وتعديله بمجرد كتابة نقطة ..

### 1. أهم الـ Methods المرتبطة بالـ String Object:

لنفترض أن لدينا الـ String التالي:
string s1 = "My Name is Mohammed Abu-Hadhoud, I love Programming.";

s1.length(): تُرجع طول الـ String (عدد الـ Characters بداخله).

s1.at(index): تُرجع الـ Character الموجود في الـ Index المحدد. (تذكر أن الـ Index يبدأ من 0).

s1.append(" text"): تقوم بالإضافة (Concatenation) وربط نص جديد بنهاية الـ String الحالي.

s1.insert(position, " text"): تقوم بعمل Insert لنص جديد في Index معين داخل الـ String دون مسح ما بعده، بل تزيحه للأسفل.

s1.substr(position, length): تقوم باقتطاع جزء من الـ String وتُرجع Sub-string. نعطيها نقطة البداية (Position) وطول المقطع الذي نريده (Length).

s1.push_back('char'): تُضيف Character واحد فقط إلى نهاية الـ String (تعمل بنفس مبدأ الـ Stack كما في الـ Vector).

s1.pop_back(): تحذف آخر Character موجود في الـ String.

s1.find("text"): تبحث عن كلمة معينة داخل الـ String، وإذا وجدتها تُرجع لك الـ Index الخاص بأول حرف منها. (تذكر أنها Case-Sensitive، أي أن A تختلف عن a).

s1.clear(): تقوم بتنظيف الـ String ومسح كل محتوياته ليصبح فارغاً تماماً.

### 2. التريكة الهندسية مع دالة find (string::npos):

ماذا يحدث لو استخدمت s1.find("ali") وكانت الكلمة غير موجودة في الـ String؟
الدالة لن تُرجع 0 (لأن 0 يمثل الـ Index الأول)، بل ستُرجع رقماً عشوائياً ضخماً جداً وغير منطقي.

لحل هذه المشكلة، وفرت لنا C++ قيمة ثابتة تُسمى string::npos (والتي تعني No Position). نستخدم هذه القيمة داخل جملة if لنتأكد هل الكلمة موجودة فعلاً أم لا:

<div dir="ltr">

```cpp
if (s1.find("ali") == string::npos)
{
    cout << "Word is not found!";
}

```

</div>

💻 تطبيق عملي شامل لجميع الـ Methods:

<div dir="ltr">

```cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "My Name is Mohammed Abu-Hadhoud, I love Programming.";

    // 1. length()
    cout << "1. Length of string: " << s1.length() << endl;

    // 2. at(index)
    cout << "2. Character at index 3: " << s1.at(3) << endl; // النتيجة: N

    // 3. append()
    s1.append(" @ProgrammingAdvices");
    cout << "3. After append: " << s1 << endl;

    // 4. insert()
    // إدخال كلمة " Ali " في الـ Index رقم 7
    s1.insert(7, " Ali ");
    cout << "4. After insert: " << s1 << endl;

    // 5. substr(position, length)
    // اقتطاع 8 كراكترز ابتداءً من الـ Index رقم 16
    cout << "5. Substring: " << s1.substr(16, 8) << endl; // النتيجة: Mohammed

    // 6. push_back()
    s1.push_back('X');
    cout << "6. After push_back('X'): " << s1 << endl;

    // 7. pop_back()
    s1.pop_back();
    cout << "7. After pop_back(): " << s1 << endl;

    // 8. find() و string::npos
    cout << "8. Find 'Ali': " << s1.find("Ali") << endl; // ستُرجع الـ Index (7)

    if (s1.find("ali") == string::npos)
    {
        cout << "9. Find 'ali': Word is not found (Case Sensitive!)" << endl;
    }

    // 9. clear()
    s1.clear();
    cout << "10. After clear(), string is: [" << s1 << "]" << endl;

    return 0;
}

```

</div>

💡 الفائدة الهندسية:
تعودك على استخدام الـ Methods الجاهزة داخل الـ String Object سيوفر عليك كتابة مئات الأسطر من الكود. في المراحل القادمة (وتحديداً في الـ OOP)، ستفهم كيف تم برمجة هذه الـ Methods خلف الكواليس، ولكن الآن، من المهم جداً أن تحفظها وتعرف كيف تستخدمها بمهارة.

## 🔠 الدرس الحادي والخمسون: بعض الـ Functions من مكتبة CCTYPE

في هذا الدرس، سنتعرف على مجموعة من الـ Functions الجاهزة والموجودة في الـ Library التي تُسمى   cctype .
هذه الـ Functions تتعامل بشكل أساسي مع الـ Character الواحد (سواء لتحويل حالته أو فحصه).

### 1. الـ Functions الخاصة بالتحويل (Conversion):

toupper(char): تأخذ الـ Character (الحرف الصغير) وتُرجع الـ ASCII Code الخاص بالحرف الكبير (Upper Case). إذا قمنا بتخزين النتيجة في Variable من نوع char، سيتحول الحرف إلى Upper Case (مثال: a تصبح A).

tolower(char): عكس الـ Function السابقة، تقوم بتحويل الحرف من Upper Case إلى Lower Case.

### 2. الـ Functions الخاصة بالفحص (Checking):

جميع الـ Functions التي تبدأ بكلمة is تُرجع قيمة من نوع int.

إذا كان الشرط صحيحاً (True)، تُرجع أي رقم غير الصفر (Non-Zero Value).

إذا كان الشرط خاطئاً (False)، تُرجع صفر (0).

isupper(char): تفحص هل الـ Character هو حرف كبير أم لا.

islower(char): تفحص هل الـ Character هو حرف صغير أم لا.

isdigit(char): تفحص هل الـ Character هو رقم (Digit من 0 إلى 9) أم لا.

ispunct(char): تفحص هل الـ Character هو علامة ترقيم (Punctuation) أو Special Character (مثل !, @, #, ,) أم لا.

💻 تطبيق عملي بالكود:

<div dir="ltr">

```cpp
#include <iostream>
#include <cctype> // Library الخاصة بالـ Character Functions
using namespace std;

int main()
{
    char x = 'a';
    char w = 'A';

    cout << "--- Conversion Functions ---\n";

    // تحويل x إلى Upper Case
    x = toupper(x);
    cout << "toupper('a') returns: " << x << endl; // النتيجة: A

    // تحويل w إلى Lower Case
    w = tolower(w);
    cout << "tolower('A') returns: " << w << endl; // النتيجة: a


    cout << "\n--- Checking Functions (Returns Non-Zero for True, 0 for False) ---\n";

    char c1 = 'A';

    // فحص هل هو حرف كبير؟
    cout << "isupper('A') returns: " << isupper(c1) << endl; // النتيجة: Non-Zero (True)

    // فحص هل هو حرف صغير؟
    cout << "islower('A') returns: " << islower(c1) << endl; // النتيجة: 0 (False)

    // فحص هل هو رقم؟
    cout << "isdigit('A') returns: " << isdigit(c1) << endl; // النتيجة: 0 (False)

    // فحص هل هو علامة ترقيم/رمز؟
    cout << "ispunct('A') returns: " << ispunct(c1) << endl; // النتيجة: 0 (False)

    return 0;
}
```

</div>

💡 الفائدة الهندسية:
هذه الـ Functions أساسية جداً وستستخدمها بكثرة في الخوارزميات (Algorithms) المتقدمة، مثل برامج التحقق من قوة الـ Passwords، أو تشفير النصوص، أو تنظيف الـ Data المدخلة من قِبل الـ User.

</div>
