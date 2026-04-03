<div dir="rtl">

# كورس 07: الخوارزميات وحل المشاكل - المستوى الثالث

# Algorithms & Problem Solving Level 3

### في هذا الكورس، ننتقل إلى مستوى متقدم من التفكير المنطقي (Logic) مع التركيز المكثف على الـ Matrices (المصفوفات ثنائية الأبعاد - 2D Arrays).

## 🧩 Problem #01: 3x3 Random Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بإنشاء Matrix بحجم 3x3، وتعبئة جميع عناصرها بأرقام عشوائية (Random Numbers) تتراوح بين 1 و 100، ثم طباعتها على الشاشة بشكل مرتب.

### 💡 الفكرة البرمجية (Logic Breakdown)

• المصفوفة ثنائية الأبعاد (2D Array): تُعرّف كالتالي int matrix[3][3].

• التعبئة (Filling): للوصول إلى كل خلية داخل الـ Matrix، نستخدم Nested Loops (حلقات متداخلة).

• الحلقة الخارجية (Outer Loop) تمر على الـ Rows (الصفوف).

• الحلقة الداخلية (Inner Loop) تمر على الـ Columns (الأعمدة).

• التوليد العشوائي (Random Generation): نستخدم دالة تعتمد على rand() مع عمل srand() مرة واحدة فقط داخل الـ main.

### 💻 الكود المعتمد (Solution)

• تم دمج أفضل ما في حل المستخدم وحل الدكتور (إزالة الدوال غير المستخدمة، مع الاحتفاظ بالتنسيق الجمالي للمستخدم).

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Function to generate a random number within a specific range
int RandomNumber(int From, int To)
{
int randNum = rand() % (To - From + 1) + From;
return randNum;
}

// Function to fill the Matrix using Nested Loops
void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
for (short i = 0; i < rows; i++)
{
for (short j = 0; j < cols; j++)
{
matrix[i][j] = RandomNumber(1, 100);
}
}
}

// Function to print the Matrix with formatting
void PrintMatrix(int matrix[3][3], short rows, short cols)
{
cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers:\n\n";
for (short i = 0; i < rows; i++)
{
for (short j = 0; j < cols; j++)
{
// setw(3) ensures alignment of columns regardless of number digits
cout << "\t" << setw(3) << matrix[i][j];
}
cout << endl;
}
}

int main()
{
// Seeds the random number generator in C++, called only once
srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #01 : Fill a 3x3 Matrix with Random Numbers";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;

}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• تم استخدام Data Type من نوع short لعدادات الـ Loops (i و j) لتقليل استهلاك الـ Memory كوننا نتعامل مع أحجام صغيرة جداً (3 صفوف فقط).

• الدالة setw(3) من مكتبة <iomanip> تعتبر الـ Best Practice لضمان ظهور الـ Matrix بشكل هندسي سليم، حيث تحجز 3 خانات لكل رقم، مما يمنع تشوه الأعمدة إذا اختلفت عدد الخانات (مثلاً رقم 9 بجوار رقم 100).

## 🧩 Problem #02: Sum Each Row In Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بإنشاء Matrix بحجم 3x3 وتعبئتها بأرقام عشوائية (كما فعلنا في المسألة الأولى)، ثم يقوم بحساب المجموع (Sum) لكل صف (Row) على حدة، ويطبع مجاميع الصفوف مرتبة على الشاشة.

### 💡 الفكرة البرمجية (Logic Breakdown)

• إعادة الاستخدام (Reusability): سنقوم بإعادة استخدام نفس الـ Functions السابقة الخاصة بتوليد الأرقام العشوائية وطباعة الـ Matrix.

• حساب مجموع الصف (Row Sum Logic): \* نُنشئ Function تستقبل الـ Matrix، ورقم الصف المطلوب (RowNumber).

• نقوم بتثبيت الـ RowNumber، ونمرر حلقة تكرار (Loop) على الأعمدة (Columns) الخاصة بهذا الصف فقط لجمع قيمها.

• طباعة المجاميع: ننشئ Function أخرى تمر بحلقة تكرار على جميع الـ Rows، وفي كل لفة تستدعي دالة المجموع وتطبع الناتج.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers:\n\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to calculate the sum of a specific row
int RowSum(int matrix[3][3], short rowNumber, short cols)
{
    int sum = 0;
    // Notice that 'rowNumber' is fixed, we only iterate over 'j' (Columns)
    for (short j = 0; j < cols; j++)
    {
        sum += matrix[rowNumber][j];
    }
    return sum;
}

// Function to print the sum of each row
void PrintEachRowSum(int matrix[3][3], short rows, short cols)
{
    cout << "\nThe Following are the sums of each row in the matrix:\n\n";
    for (short i = 0; i < rows; i++)
    {
        // Calling RowSum for each specific row 'i'
        cout << "\tRow " << i + 1 << " Sum = " << RowSum(matrix, i, cols) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #02 : Sum Each Row in Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);
    PrintEachRowSum(matrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Single Responsibility Principle (SRP): في هذا الحل، قمنا بفصل الـ Logic بذكاء. دالة RowSum مسؤولة فقط عن الحساب (Calculation)، ودالة PrintEachRowSum مسؤولة فقط عن الطباعة (Printing). هذا الفصل يسهل جداً عملية صيانة الكود لاحقاً وإعادة استخدامه.

• Time Complexity: الأداء هنا ممتاز ومثالي $O(R \times C)$، حيث تمر الـ Loops على كل عنصر في المصفوفة مرة واحدة للتعبئة، ومرة واحدة للحساب.

## 🧩 Problem #03: Sum Matrix Rows in Array

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بإنشاء Matrix بحجم 3x3 وتعبئتها بأرقام عشوائية، ثم يقوم بحساب المجموع لكل صف وتخزين هذا المجموع في مصفوفة أحادية (1D Array) منفصلة، وأخيراً طباعة محتويات هذه المصفوفة.

### 💡 الفكرة البرمجية (Logic Breakdown)

• مصفوفة أحادية (1D Array): نُعرف مصفوفة عادية بحجم 3 لتخزين نواتج الجمع لكل صف.

• تخزين المجاميع: نُنشئ Function تمر على صفوف الـ Matrix، وفي كل لفة تستدعي دالة RowSum وتُخزن الناتج في الـ Index المقابل في المصفوفة الأحادية.

• الطباعة: نُنشئ Function بسيطة للمرور على المصفوفة الأحادية وطباعة محتوياتها.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers:\n\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

int RowSum(int matrix[3][3], short rowNumber, short cols)
{
    int sum = 0;
    for (short j = 0; j < cols; j++)
    {
        sum += matrix[rowNumber][j];
    }
    return sum;
}

// Function to calculate rows sum and store them in a 1D Array
void SumMatrixRowsInArray(int matrix[3][3], int rowsSum[3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        // Store the sum of row 'i' into the array at index 'i'
        rowsSum[i] = RowSum(matrix, i, cols);
    }
}

// Function to print the 1D Array
void PrintRowsSumArray(int rowsSum[3], short rows)
{
    cout << "\nThe Following are the sums of each row in the matrix:\n\n";
    for (short i = 0; i < rows; i++)
    {
        cout << "\tRow " << i + 1 << " Sum = " << rowsSum[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #03 : Sum Matrix Rows in Array";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];
    int rowsSum[3]; // 1D Array to hold the sums

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);
    
    SumMatrixRowsInArray(matrix, rowsSum, 3, 3);
    PrintRowsSumArray(rowsSum, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• فصل البيانات (Separation of Data): تخزين البيانات المُعالجة (المجاميع) في Data Structure منفصلة (المصفوفة الأحادية) بدلاً من طباعتها مباشرة يُعتبر من أفضل الممارسات، لأنه يسمح لك باستخدام هذه المجاميع لاحقاً في عمليات حسابية أخرى داخل البرنامج بدون الحاجة لإعادة حسابها.

## 🧩 Problem #04: Sum Each Column In Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بإنشاء Matrix بحجم 3x3 وتعبئتها بأرقام عشوائية، ثم يقوم بحساب المجموع لكل عمود (Column) على حدة، ويطبع مجاميع الأعمدة مرتبة على الشاشة.

### 💡 الفكرة البرمجية (Logic Breakdown)

• التفكير المعكوس (Inverted Logic): لحساب مجموع العمود، نثبت رقم العمود (Column Number) ونجعل حلقة التكرار (Loop) تمر على الصفوف (Rows).

• في دالة ColSum، المتغير الذي يزداد في حلقة التكرار هو المتغير الخاص بالصفوف (i)، بينما يظل متغير الأعمدة ثابتاً.

💻 الكود المعتمد (Solution)

```cpp
<div dir="ltr">

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers:\n\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to calculate the sum of a specific column
int ColSum(int matrix[3][3], short rows, short colNumber)
{
    int sum = 0;
    // Notice that 'colNumber' is fixed, we only iterate over 'i' (Rows)
    for (short i = 0; i < rows; i++)
    {
        sum += matrix[i][colNumber];
    }
    return sum;
}

// Function to print the sum of each column
void PrintEachColSum(int matrix[3][3], short rows, short cols)
{
    cout << "\nThe Following are the sums of each column in the matrix:\n\n";
    for (short j = 0; j < cols; j++)
    {
        // Calling ColSum for each specific column 'j'
        cout << "\tCol " << j + 1 << " Sum = " << ColSum(matrix, rows, j) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #04 : Sum Each Column in Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);
    PrintEachColSum(matrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```
</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• الوصول للأعمدة (Column Access): في المصفوفة ثنائية الأبعاد، الوصول لعناصر العمود الواحد يتطلب القفز في الذاكرة (لأن العناصر تُخزن صفاً بصف)، ولذلك قمنا بتثبيت الفهرس الثاني matrix[i][colNumber] وتحريك الفهرس الأول i للمرور عمودياً.

## 🧩 Problem #05: Sum Matrix Columns in Array

### 📝 وصف المشكلة (Problem Description)

المطلوب حساب مجموع كل عمود في الـ Matrix وتخزين هذه المجاميع في مصفوفة أحادية (1D Array) منفصلة، ثم طباعة محتوياتها على الشاشة.

### 💡 الفكرة البرمجية (Logic Breakdown)

• تجميع الأفكار: ندمج فكرة تخزين البيانات في مصفوفة أحادية (من المسألة 3) مع فكرة حساب مجموع الأعمدة (من المسألة 4).

• نُنشئ مصفوفة أحادية بحجم 3، ونمرر حلقة تكرار على الأعمدة، وفي كل لفة نحسب المجموع (باستخدام ColSum) ونضعه في الـ Index المقابل في المصفوفة الأحادية.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers:\n\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

int ColSum(int matrix[3][3], short rows, short colNumber)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        sum += matrix[i][colNumber];
    }
    return sum;
}

// Function to calculate columns sum and store them in a 1D Array
void SumMatrixColsInArray(int matrix[3][3], int colsSum[3], short rows, short cols)
{
    for (short j = 0; j < cols; j++)
    {
        // Store the sum of column 'j' into the array at index 'j'
        colsSum[j] = ColSum(matrix, rows, j);
    }
}

// Function to print the 1D Array
void PrintColsSumArray(int colsSum[3], short cols)
{
    cout << "\nThe Following are the sums of each column in the matrix:\n\n";
    for (short i = 0; i < cols; i++)
    {
        cout << "\tCol " << i + 1 << " Sum = " << colsSum[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #05 : Sum Matrix Columns in Array";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];
    int colsSum[3]; // 1D Array to hold the sums

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);
    
    SumMatrixColsInArray(matrix, colsSum, 3, 3);
    PrintColsSumArray(colsSum, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• إعادة الاستخدام (Code Reusability): لاحظ كيف أننا استخدمنا نفس دالة ColSum التي كتبناها في المسألة السابقة دون أي تعديل، فقط قمنا بتغيير المكان الذي نضع فيه الناتج. هذا هو جوهر كتابة كود نظيف وقابل للتوسع والصيانة بسهولة.

## 🧩 Problem #06: 3x3 Ordered Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بإنشاء Matrix بحجم 3x3، وتعبئة عناصرها بأرقام تسلسلية مرتبة (Ordered Numbers) من 1 إلى 9، ثم طباعتها على الشاشة بشكل مرتب.

### 💡 الفكرة البرمجية (Logic Breakdown)

• تعريف عداد (Counter): نقوم بإنشاء متغير بسيط ونعطيه قيمة ابتدائية 1.

• التعبئة (Filling): باستخدام حلقات التكرار المتداخلة (Nested Loops)، نمر على كل عنصر في المصفوفة، ونسند إليه قيمة العداد الحالي، ثم نزيد العداد بمقدار 1 للخطوة التالية.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

// Function to fill the Matrix with ordered numbers (1, 2, 3...)
void FillMatrixWithOrderedNumbers(int matrix[3][3], short rows, short cols)
{
    short counter = 1;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = counter++;
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Ordered Numbers:\n\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #06 : Fill a 3x3 Matrix with Ordered Numbers";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithOrderedNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Post-Increment Operator (counter++): استخدام معامل الزيادة اللاحقة يسمح لنا بوضع القيمة الحالية للعداد داخل المصفوفة، ثم زيادة العداد بمقدار 1 في نفس السطر. هذا يجعل الكود أنظف وأقصر.

## 🧩 Problem #07: Transpose Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج لإنشاء مصفوفة مرتبة (كما في المسألة السابقة) وطباعتها. ثم يتم عمل منقول (Transpose) لهذه المصفوفة وحفظه في مصفوفة أخرى وطباعة المصفوفة الناتجة.

### 💡 الفكرة البرمجية (Logic Breakdown)

• مفهوم الـ Transpose: منقول المصفوفة رياضياً يعني تحويل الصفوف إلى أعمدة، والأعمدة إلى صفوف.

• طريقة التنفيذ: في حلقات التكرار المتداخلة، نقوم بنسخ العنصر الموجود في الصف i والعمود j من المصفوفة الأصلية، ونضعه في الصف j والعمود i في المصفوفة الجديدة. أي أن transposedMatrix[i][j] = matrix[j][i].

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int matrix[3][3], short rows, short cols)
{
    short counter = 1;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = counter++;
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to transpose the matrix
void TransposeMatrix(int matrix[3][3], int transposedMatrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            // Swap the indices to transpose
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #07 : Transpose a 3x3 Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];
    int transposedMatrix[3][3];

    // Execution
    FillMatrixWithOrderedNumbers(matrix, 3, 3);
    
    cout << "The Following is the Original Matrix:\n\n";
    PrintMatrix(matrix, 3, 3);

    TransposeMatrix(matrix, transposedMatrix, 3, 3);
    
    cout << "\nThe Following is the Transposed Matrix:\n\n";
    PrintMatrix(transposedMatrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```
</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Index Manipulation: التلاعب بمؤشرات المصفوفات (i و j) هو جوهر التعامل مع الـ Data Structures. عكس الفهارس هنا حقق عملية رياضية معقدة بكود بسيط جداً وبدون استخدام دوال مساعدة إضافية.

## 🧩 Problem #08: Multiply Two Matrices

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج لتعبئة مصفوفتين 3x3 بأرقام عشوائية من 1 إلى 10 وطباعتهما، ثم ضرب كل عنصر في المصفوفة الأولى مع العنصر المقابل له في المصفوفة الثانية وحفظ النتيجة في مصفوفة ثالثة وطباعتها.

### 💡 الفكرة البرمجية (Logic Breakdown)

• التعبئة والضرب: نستخدم نفس اللوجيك السابق لإنشاء مصفوفتين وتعبئتهما عشوائياً.

• عملية الضرب المباشر: نمر بحلقات التكرار على المصفوفتين، وفي كل دورة نقوم بضرب العنصر [i][j] من الأولى بالعنصر [i][j] من الثانية، ونخزن الناتج في المصفوفة الثالثة.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to multiply two matrices element by element
void MultiplyMatrix(int matrix1[3][3], int matrix2[3][3], int resultMatrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            resultMatrix[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #08 : Multiply Two Matrices Element by Element";
    cout << "\n-------------------------------------------------\n\n";

    int matrix1[3][3], matrix2[3][3], resultMatrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    FillMatrixWithRandomNumbers(matrix2, 3, 3);

    cout << "The First Matrix:\n\n";
    PrintMatrix(matrix1, 3, 3);

    cout << "\nThe Second Matrix:\n\n";
    PrintMatrix(matrix2, 3, 3);

    MultiplyMatrix(matrix1, matrix2, resultMatrix, 3, 3);

    cout << "\nThe Result Matrix (Matrix1 * Matrix2):\n\n";
    PrintMatrix(resultMatrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```
</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Element-wise Multiplication: لاحظ أن هذا الضرب هو ضرب مباشر للعناصر المتقابلة (Element-wise) وليس الضرب الرياضي المتقدم للمصفوفات (Matrix Multiplication). وهذا مثالي جداً في تطبيقات تعديل الصور (Image Masks) ومؤثرات الرؤية الرقمية.

## 🧩 Problem #09: Print Middle Row and Col of Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج لتعبئة مصفوفة 3x3 بأرقام عشوائية، وطباعتها. ثم استخراج وطباعة عناصر الصف الأوسط (Middle Row) والعمود الأوسط (Middle Column) بشكل مستقل.

### 💡 الفكرة البرمجية (Logic Breakdown)

• حساب نقطة المنتصف: المصفوفة حجمها 3x3 (فهارسها: 0, 1, 2). بقسمة حجم الصفوف أو الأعمدة على 2 (3/2)، نحصل على الرقم 1 (بحكم أن نوع البيانات Integer يحذف الكسر)، وهذا هو فهرس المنتصف تماماً.

• طباعة الصف الأوسط: نثبت الفهرس الأول (الخاص بالصفوف) عند المنتصف، ونغير الفهرس الثاني بحلقة تكرار لطباعة الأعمدة.

• طباعة العمود الأوسط: نثبت الفهرس الثاني (الخاص بالأعمدة) عند المنتصف، ونغير الفهرس الأول بحلقة تكرار لطباعة الصفوف.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to print the middle row
void PrintMiddleRow(int matrix[3][3], short rows, short cols)
{
    short middleRowIndex = rows / 2;
    cout << "The Middle Row is    : ";
    for (short j = 0; j < cols; j++)
    {
        cout << setw(3) << matrix[middleRowIndex][j] << "  ";
    }
    cout << endl;
}

// Function to print the middle column
void PrintMiddleCol(int matrix[3][3], short rows, short cols)
{
    short middleColIndex = cols / 2;
    cout << "The Middle Column is : ";
    for (short i = 0; i < rows; i++)
    {
        cout << setw(3) << matrix[i][middleColIndex] << "  ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #09 : Print Middle Row and Col of Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    
    cout << "The Following is a 3x3 Matrix:\n\n";
    PrintMatrix(matrix, 3, 3);
    
    cout << "\n";
    PrintMiddleRow(matrix, 3, 3);
    PrintMiddleCol(matrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Integer Division: الاستفادة من ميزة قسمة الـ Integers (بإهمال الكسور) هي طريقة ممتازة لتحديد نقطة ارتكاز (Center Point) في أي هيكل بيانات فردي الحجم دون الحاجة لكتابة كود معقد للتقريب.

## 🧩 Problem #10: Sum of Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج لإنشاء مصفوفة 3x3 عشوائية وطباعتها، ثم حساب المجموع الكلي (Sum) لجميع العناصر الموجودة بداخل هذه المصفوفة وطباعته.

### 💡 الفكرة البرمجية (Logic Breakdown)

• المُجمّع (Accumulator): نقوم بإنشاء متغير بسيط sum = 0 ونضعه خارج حلقات التكرار.

• المرور والتجميع: نستخدم حلقتي تكرار متداخلتين للمرور على كل عنصر في المصفوفة، وفي كل دورة نقوم بجمع قيمة العنصر الحالي وإضافتها إلى المتغير sum.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to calculate the sum of all elements in the matrix
int SumOfMatrix(int matrix[3][3], short rows, short cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #10 : Sum of All Numbers in Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    
    cout << "The Following is a 3x3 Matrix:\n\n";
    PrintMatrix(matrix, 3, 3);

    int totalSum = SumOfMatrix(matrix, 3, 3);
    cout << "\nThe Sum of all numbers in the matrix is : " << totalSum << endl;

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```
</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Time Complexity: حساب مجموع كامل المصفوفة يتطلب المرور على كل العناصر دفعة واحدة، مما يجعل الأداء $O(R \times C)$ وهو الأداء الطبيعي والأمثل لهذه العملية.

</div>


