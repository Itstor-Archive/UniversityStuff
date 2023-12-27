#include <iostream>
#include <string>

struct Coordinate {
    Coordinate(int x, int y) : x(x), y(y) {}

    int x, y;
};

template<typename T>
class Stack {
    
    template<typename A>
    class Node {
    public:
        Node() = default;
        Node(A* data) : data(data), previous(nullptr) {}

        ~Node()
        {
            delete data;
        }

        A* data = nullptr;
        Node<A>* previous = nullptr;
    };

public:
    Stack()
    {
        mCurrentNode = new Node<T>;
    }

    void push(T object)
    {
	    auto* tempNode = new Node<T>(new T(object));
        tempNode->previous = mCurrentNode;
        mCurrentNode = tempNode;
        mSize++;
    }

    T pop()
    {
        T temp = *mCurrentNode->data;
        Node<T>* tempNode = mCurrentNode->previous;
        delete mCurrentNode;
        mCurrentNode = tempNode;
        mSize--;
        return temp;
    }

    bool empty() const
    {
        return mSize == 0 ? true : false;
    }

    size_t size() const
    {
        return mSize;
    }

    T& top()
    {
        return *mCurrentNode->data;
    }

private:
    Node<T>* mCurrentNode;
    size_t mSize = 0;
};


class City {
public:
    City(std::string city_name, Coordinate coordinate) :
        mCityName(std::move(city_name)), mCityCoordinate(coordinate) {}

    std::string printCoordinate() const
    {
        return "(" + std::to_string(mCityCoordinate.x) + ", "
            + std::to_string(mCityCoordinate.y) + ")";
    }

    std::string mCityName;
    Coordinate mCityCoordinate;

    //float memoryTest[9999];
    //float memoryTest2[9999];
    //float memoryTest3[9999];
};

int main() {
    Stack<City> Maps;
    int choice;

    do {
        std::cout << "\n1. Tambah kota (push())\n";
        std::cout << "2. Hapus kota (pop())\n";
        std::cout << "3. Kota teratas (top())\n";
        std::cout << "4. Apakah maps kosong? (empty())\n";
        std::cout << "5. Cetak ukuran (size())\n";
        std::cout << "6. Keluar\n";
        std::cout << "Masukkan pilihan: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string tempCityName;
            int x, y;

            std::cout << "Nama Kota: "; std::cin >> tempCityName;
            std::cout << "Koordinat kota (x, y): ";
            std::cin >> x >> y; std::cout << std::endl;
            Maps.push(City(tempCityName, { x, y }));
            break;
        }
        case 2:
        {
            City temp = Maps.pop();
            std::cout << "Nama Kota yang dihapus adalah "
                << temp.mCityName << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "Nama Kota teratas dalam maps adalah "
                << Maps.top().mCityName << " dengan koordinat"
                << Maps.top().printCoordinate() << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Maps " <<
                (Maps.empty() ? "kosong\n" : "tidak kosong\n");
            break;
        }
        case 5:
        {
            std::cout << Maps.size() << std::endl;
            break;
        }
        case 6: break;
        default: std::cout << "Pilihan tidak ditemukan\n"; break;
        }
    } while (choice != 6);
}