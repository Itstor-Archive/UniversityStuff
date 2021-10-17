#include <iostream>
#include <vector>
#include <string>

struct Coordinate {
    Coordinate(float x, float y) : x(x), y(y) {}

    float x, y;
};

class City {
public:
    City(std::string city_name, Coordinate coordinate) : mCityName(std::move(city_name)), mCityCoordinate(coordinate) {}
    ~City() = default;

    std::string mCityName;
    Coordinate mCityCoordinate;
};

template <typename T>
struct Stack {
    Stack() = default;

    void push(T object) {
        mContainer.push_back(std::make_unique<T>(object));
    }

    T pop() {
        T temp = *mContainer.back();

        mContainer.pop_back();

        return std::move(temp);
    }

    void empty()
    {
        mContainer.clear();
    }

    T& top()
    {
        return *mContainer.back();
    }

    size_t size()
    {
        return mContainer.size();
    }

private:
    std::vector<std::unique_ptr<T>> mContainer;
};

int main() {
    Stack<City> Maps;

    Maps.push({ "hello", {2, 3} });

    const City hello = Maps.top();

    std::cout << hello.mCityName << std::endl;

    std::cout << Maps.size() << std::endl;
}