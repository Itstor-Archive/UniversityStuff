#include <string>
#include <iostream>
#include <algorithm>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class CityPoint : public sf::Drawable
{
public:
    CityPoint(const std::string &city_name, const std::string &coordinate, const sf::Vector2f &position, const sf::Font &font)
    {
        mPosition = position;
        mCityName.setFont(font);
        mCoordinateText.setFont(font);
        mCoordinateText.setString(coordinate);
        mCityName.setString(city_name);
        mCityName.setCharacterSize(28);
        mCoordinateText.setCharacterSize(24);
        mCityName.setOrigin(mCityName.getLocalBounds().width / 2, mCityName.getLocalBounds().height / 2);
        mCoordinateText.setOrigin(mCoordinateText.getLocalBounds().width / 2, mCoordinateText.getLocalBounds().height / 2);
        mCoordinateText.setPosition(mPosition.x, mPosition.y + 55.0f);
        mCityName.setPosition(mPosition.x, mPosition.y - 65.0f);
        mNode.setPosition(mPosition);
        mNode.setRadius(40.0f);
        mNode.setOrigin(mNode.getRadius(), mNode.getRadius());
        mNode.setFillColor(sf::Color(0, 255, 0));
    }

    void connect(const CityPoint &target)
    {
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = mPosition;
        line[1].position = target.getPosition();
        mConnectedLine.push_back(line);
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {

        if (!mConnectedLine.empty())
        {
            for (auto &line : mConnectedLine)
            {
                target.draw(line);
            }
        }

        target.draw(mNode);
        target.draw(mCityName);
        target.draw(mCoordinateText);
    }

    sf::Vector2f getPosition() const
    {
        return mPosition;
    }

private:
    sf::Font openSans;
    sf::CircleShape mNode;
    sf::Vector2f mPosition;
    sf::Text mCoordinateText;
    sf::Text mCityName;
    std::vector<sf::VertexArray> mConnectedLine;
};

struct Coordinate
{
    Coordinate() = default;
    Coordinate(int x, int y) : x(x), y(y) {}

    friend std::ostream &operator<<(std::ostream &os, const Coordinate &c)
    {
        return os << "(" + std::to_string(c.x) + ", " + std::to_string(c.y) + ")";
    }

    std::string formatedString() const
    {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    int x = 0;
    int y = 0;
};

class City
{
public:
    City()
    {
        std::fill_n(mConnected, std::size(mConnected), -1);
    }

    City(std::string city_name, int x, int y) : mCityName(std::move(city_name)), mCoordinate(x, y)
    {
        std::fill_n(mConnected, std::size(mConnected), -1);
    }

    void connect(int index)
    {
        for (int i = 0; i <= mCurrentConnected; i++)
        {
            if (mConnected[i] == index)
            {
                return;
            }
        }

        mCurrentConnected++;
        mConnected[mCurrentConnected] = index;
    }

    void remove(int index)
    {
        bool alreadyDeleted = false;

        for (int i = 0; i < mCurrentConnected + 1; i++)
        {
            if (mConnected[i] == index && !alreadyDeleted)
            {
                for (int j = i; j < mCurrentConnected + 1; j++)
                {
                    mConnected[j] = mConnected[j + 1];
                }
                mCurrentConnected--;
                alreadyDeleted = true;
            }

            if (mConnected[i] >= index)
            {
                mConnected[i]--;
            }
        }
    }

    void insert(int index)
    {
        for (int i = 0; i < mCurrentConnected + 1; i++)
        {
            if (mConnected[i] >= index)
            {
                mConnected[i]++;
            }
        }
    }

    std::string mCityName;
    int mConnected[10];
    int mCurrentConnected = -1;
    Coordinate mCoordinate;
};

class Maps
{

public:
    Maps(int size)
    {
        mSize = size;
        mCityContainer = new City[size];
    }

    ~Maps()
    {
        delete[] mCityContainer;
    }

    auto operator[](int index) const
    {
        return mCityContainer[index];
    }

    void print()
    {
        std::cout << "| Nama Kota |"
                  << " Kota Tersambung |" << std::endl;
        for (int i = 0; i < mCurrentSize + 1; i++)
        {
            std::cout << " " << mCityContainer[i].mCityName << mCityContainer[i].mCoordinate << "\t";
            for (int j = 0; j < mCityContainer[i].mCurrentConnected + 1; j++)
            {
                std::cout << mCityContainer[mCityContainer[i].mConnected[j]].mCityName << (j == mCityContainer[i].mCurrentConnected ? " " : ", ");
            }

            std::cout << std::endl;
        }
    }

    void insert(const std::string &city_name, int x, int y, int index)
    {
        if (mCurrentSize + 1 < mSize && index <= mCurrentSize + 1)
        {
            const City newCity(city_name, x, y);
            int back = mCurrentSize;
            while (back >= index)
            {
                mCityContainer[back].insert(index);
                mCityContainer[back + 1] = mCityContainer[back];
                back--;
            }

            for (int i = index - 1; i >= 0; i--)
            {
                mCityContainer[i].insert(index);
            }
            mCityContainer[index] = newCity;

            mCurrentSize++;
        }
    }

    Maps &addCity(const std::string &city_name, int x, int y)
    {
        const City newCity(city_name, x, y);

        if (mCurrentSize + 1 < mSize)
        {
            mCurrentSize++;
            mCityContainer[mCurrentSize] = newCity;
        }
        else
        {
            std::cout << "Maps is full\n";
        }

        return *this;
    }

    void remove(const std::string &city_name)
    {
        const int index = findCityByName(city_name);
        if (index == -1)
            return;

        for (int i = index; i < mCurrentSize; i++)
        {
            mCityContainer[i] = mCityContainer[i + 1];
            mCityContainer[i].remove(index);
        }

        for (int i = index - 1; i >= 0; i--)
        {
            mCityContainer[i].remove(index);
        }
        mCurrentSize--;
    }

    Maps &connect(const std::string &A, const std::string &B)
    {
        const int AIndex = findCityByName(A);
        const int BIndex = findCityByName(B);

        if (AIndex == -1 || BIndex == -1)
            return *this;

        mCityContainer[AIndex].connect(BIndex);

        return *this;
    }

    int findCityByName(const std::string &city_name) const
    {
        for (int index = 0; index <= mCurrentSize; index++)
        {
            if (mCityContainer[index].mCityName == city_name)
            {
                return index;
            }
        }
        return -1;
    }

    int size() const
    {
        return mCurrentSize + 1;
    }

    City &getCityContainer() const
    {
        return *mCityContainer;
    }

    void visualize()
    {
        sf::RenderWindow window(sf::VideoMode(1024, 720), "Visualize");
        sf::View view(sf::FloatRect(0.f, 0.f, 1024.f, 720.f));
        sf::Font openSans;
        std::vector<CityPoint> nodeContainer;
        sf::Vector2f clickedMousePos;
        bool mousePressed = false;

        openSans.loadFromFile("assets/opensans.ttf");

        for (int i = 0; i <= mCurrentSize; i++)
        {
            sf::Vector2f tempCoordinate(mCityContainer[i].mCoordinate.x, mCityContainer[i].mCoordinate.y);
            nodeContainer.emplace_back(mCityContainer[i].mCityName, mCityContainer[i].mCoordinate.formatedString(), tempCoordinate * 200.0f, openSans);
        }

        for (int i = 0; i <= mCurrentSize; i++)
        {
            for (auto &connected : mCityContainer[i].mConnected)
            {
                if (connected != -1)
                {
                    nodeContainer[i].connect(nodeContainer[connected]);
                }
            }
        }

        while (window.isOpen())
        {
            sf::Event event{};
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseWheelMoved)
                {
                    std::cout << event.mouseWheel.x << " " << event.mouseWheel.y << std::endl;
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

                    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
                    const sf::Vector2f center = view.getCenter();
                    std::cout << worldPos.x << " " << worldPos.y << std::endl;
                    if (event.mouseWheel.delta == -1)
                    {
                        view.zoom(1.02f);

                        sf::Vector2f movePos((worldPos.x - center.x) * 0.02f, (worldPos.y - center.y) * 0.02f);

                        view.move(movePos);
                    }
                    else
                    {
                        view.zoom(1.0f / 1.02f);
                        sf::Vector2f movePos((worldPos.x - center.x) * 0.02f, (worldPos.y - center.y) * 0.02f);

                        view.move(movePos);
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        clickedMousePos = window.mapPixelToCoords(sf::Mouse::getPosition());
                        mousePressed = true;
                    }
                }
                if (event.type == sf::Event::MouseButtonReleased)
                {
                    mousePressed = false;
                }
            }

            if (mousePressed)
            {
                const sf::Vector2f mouseCurrentPos = window.mapPixelToCoords(sf::Mouse::getPosition());
                sf::Vector2f moveView((clickedMousePos - mouseCurrentPos));
                view.move(moveView);
            }

            window.setView(view);
            window.clear();
            for (auto &node : nodeContainer)
            {
                window.draw(node);
            }
            window.display();
        }
    }

private:
    City *mCityContainer;
    int mSize;
    int mCurrentSize = -1;
};

template <typename T>
class Stack
{
public:
    Stack(int size)
    {
        mArray = new T[size];
    }

    Stack(const T *arr, int current_size, int size)
    {
        mCurrentSize = current_size;
        mArray = new T[size];
        std::copy_n(arr, mCurrentSize + 1, mArray);
    }

    void push(T object)
    {
        this->mArray[this->mCurrentSize + 1] = std::move(object);
        ++this->mCurrentSize;
    }

    T &top()
    {
        return this->mArray[this->mCurrentSize];
    }

    int size()
    {
        return this->mCurrentSize;
    }

    bool empty()
    {
        return this->mCurrentSize == 0 ? true : false;
    }

    T pop()
    {
        T temp = this->mArray[this->mCurrentSize];

        --this->mCurrentSize;
        return temp;
    }

    static Stack make_stack(const T *object, int current_size, int array_size)
    {
        return Stack(object, current_size, array_size);
    }

private:
    T *mArray;
    int mCurrentSize = 0;
};

template <typename T>
class Queue
{
public:
    Queue(int size)
    {
        mArray = new T[size];
    }

    Queue(const T *arr, int current_size, int size)
    {
        mCurrentSize = current_size;
        mArray = new T[size];
        std::copy_n(arr, mCurrentSize + 1, mArray);
    }

    void put(T object)
    {
        this->mArray[this->mCurrentSize + 1] = std::move(object);
        ++this->mCurrentSize;
    }

    int size()
    {
        return this->mCurrentSize;
    }

    bool empty()
    {
        return this->mCurrentSize == 0 ? true : false;
    }

    T get()
    {
        T temp = this->mArray[0];

        for (int i = 0; i < mCurrentSize; i++)
        {
            mArray[i] = mArray[i + 1];
        }

        --this->mCurrentSize;
        return std::move(temp);
    }

    static Queue make_queue(const T *object, int current_size, int array_size)
    {
        return Queue(object, current_size, array_size);
    }

private:
    T *mArray; 
    int mCurrentSize = 0;
};

int main()
{
    Maps maps(10);

    maps.addCity("A", 0, 1)
        .addCity("B", 1, 0)
        .addCity("C", 1, 2)
        .addCity("D", 2, -1)
        .addCity("E", 2, 0)
        .addCity("F", 2, 1)
        .addCity("G", 2, 2)
        .addCity("H", 2, 3)
        .addCity("I", 1, 3);

    maps.connect("A", "B")
        .connect("A", "C")
        .connect("A", "I")
        .connect("B", "F")
        .connect("B", "E")
        .connect("B", "D")
        .connect("C", "H")
        .connect("C", "G");

    std::cout << "Daftar Kota" << std::endl;
    maps.print();

    Stack<City> stackMaps = Stack<City>::make_stack(&maps.getCityContainer(), maps.size() - 1, 20);

    std::cout << "stackMaps saat di-pop: " << stackMaps.pop().mCityName << std::endl;
    std::cout << "Top dari stackMaps setelah di-pop: " << stackMaps.top().mCityName << std::endl;
    stackMaps.push({"Z", 2, 4});
    std::cout << "Top dari stackMaps setelah penambahan menggunakan push(): " << stackMaps.top().mCityName << std::endl;

    Queue<City> queueMaps = Queue<City>::make_queue(&maps.getCityContainer(), maps.size() - 1, 20);

    std::cout << "Pemanggilan get() pertama pada queueMaps: " << queueMaps.get().mCityName << std::endl;
    std::cout << "Pemanggilan get() kedua queueMaps: " << queueMaps.get().mCityName << std::endl;

    maps.visualize();

    return 0;
}