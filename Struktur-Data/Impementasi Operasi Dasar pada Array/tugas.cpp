#include <iostream>

using namespace std;

template <typename T>
struct CustomArray
{
    CustomArray(int size)
    {
        mArray = new T[size];
        mSize = size;
    }

    CustomArray(const T *arr, int size, int array_size)
    {
        mSize = size;
        mArray = new T[size];
        mCurrSize = array_size - 1;

        for (int i = 0; i <= mCurrSize; i++)
        {
            mArray[i] = arr[i];
        }
    }

    void print()
    {
        cout << "[";
        for (int i = 0; i <= mCurrSize; i++)
        {
            cout << mArray[i] << (i == mCurrSize ? "" : ", ");
        }
        cout << "]";
        cout << endl;
    }
    void insert(T X, int index)
    {
        if (mCurrSize + 1 < mSize && index <= mCurrSize + 1)
        {
            int back = mCurrSize;
            while (back >= index)
            {
                mArray[back + 1] = mArray[back];
                back--;
            }

            mArray[index] = X;
            mCurrSize++;
        }
    }
    void append(T X)
    {
        if (mCurrSize + 1 < mSize)
        {
            mCurrSize++;
            mArray[mCurrSize] = X;
        }
        else
        {
            cout << "CustomArray is full\n";
        }
    }

    void remove(int index)
    {
        if (index >= 0 && index <= mCurrSize)
        {
            for (int i = index; i <= mCurrSize; i++)
            {
                mArray[i] = mArray[i + 1];
            }
            mCurrSize--;
        }
        else
        {
            cout << "Index out of bounds\n";
        }
    }

    int search(T X)
    {
        for (int index = 0; index <= mCurrSize; index++)
        {
            if (mArray[index] == X)
            {
                return index;
            }
        }
        return -1;
    }

    void clear()
    {
        while (mCurrSize >= 0)
        {
            remove(0);
        }
    }

    int findMaxValue(bool ret_index = false)
    {
        auto max = mArray[0];

        for (int i = 1; i <= mCurrSize; i++)
        {
            if (max < mArray[i])
            {
                max = mArray[i];
            }
        }

        if (ret_index)
            return search(max);
        return max;
    }

    void removeMaxValue()
    {
        remove(findMaxValue(true));
    }

    void update(T X, int index)
    {
        if (index <= mCurrSize)
        {
            mArray[index] = X;
        }
    }

private:
    T *mArray;
    int mSize;
    int mCurrSize = -1;
};

int main()
{
    float arr[] = {100.2f, 237.1f, 127.24f};
    CustomArray<float> definedArray(arr, 10, sizeof(arr) / sizeof(arr[0]));
    CustomArray<int> emptyArray(4);

    cout << "Mencetak Array definedArray:\n";
    definedArray.print();
    cout << "Menambahkan 81, 83, 72, 100 ke dalam emptyArray:\n";
    emptyArray.append(81);
    emptyArray.append(83);
    emptyArray.append(72);
    emptyArray.append(10);
    emptyArray.print();
    cout << "Menghapus element dengan index 1 pada emptyArray:\n";
    emptyArray.remove(1);
    emptyArray.print();
    cout << "Memasukkan angka 100 index 2 pada emptyArray:\n";
    emptyArray.insert(100, 2);
    emptyArray.print();
    cout << "Index angka 100 pada emptyArray:\n";
    cout << emptyArray.search(100) << endl;
    cout << "Angka maksimum pada emptyArray:\n";
    cout << emptyArray.findMaxValue() << endl;
    cout << "Menghapus angka maksimum pada emptyArray:\n";
    emptyArray.removeMaxValue();
    emptyArray.print();
    cout << "Menghapus seluruh isi emptyArray:\n";
    emptyArray.clear();
    emptyArray.print();

    return 0;
}