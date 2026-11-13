#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    size_t length;

public:
    String() : str(new char[1] {'\0'}), length(0) {}

    String(const char* s) {
        if (s) {
            length = std::strlen(s);
            str = new char[length + 1];
            std::strcpy(str, s);
        }
        else {
            length = 0;
            str = new char[1] {'\0'};
        }
    }

    String(const String& other) : length(other.length) {
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    String(String&& other) noexcept : str(other.str), length(other.length) {
        other.str = nullptr;
        other.length = 0;
    }

    ~String() {
        delete[] str;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] str;
            str = other.str;
            length = other.length;
            other.str = nullptr;
            other.length = 0;
        }
        return *this;
    }

    size_t size() const {
        return length;
    }

    const char* c_str() const {
        return str ? str : "";
    }

    void print() const {
        if (str) {
            std::cout << str << "\n";
        }
    }
};

class Reservoir {
private:
    String name;
    String type;
    double width;
    double length;
    double maxDepth;

public:
    Reservoir() : name("Default"), type("Unknown"), width(0.0), length(0.0), maxDepth(0.0) {}

    explicit Reservoir(const char* n) : name(n), type("Unknown"), width(0.0), length(0.0), maxDepth(0.0) {}

    Reservoir(const char* n, const char* t, double w, double l, double d)
        : name(n), type(t), width(w), length(l), maxDepth(d) {
    }

    Reservoir(const Reservoir& other)
        : name(other.name), type(other.type), width(other.width), length(other.length), maxDepth(other.maxDepth) {
    }

    ~Reservoir() {}

    double calculateVolume() const {
        return width * length * maxDepth;
    }

    double calculateSurfaceArea() const {
        return width * length;
    }

    bool isSameType(const Reservoir& other) const {
        return std::strcmp(type.c_str(), other.type.c_str()) == 0;
    }

    int compareSurfaceArea(const Reservoir& other) const {
        if (!isSameType(other)) {
            return -2;
        }
        double area1 = calculateSurfaceArea();
        double area2 = other.calculateSurfaceArea();
        if (area1 > area2) return 1;
        if (area1 < area2) return -1;
        return 0;
    }

    void setName(const char* n) { name = n; }
    void setType(const char* t) { type = t; }
    void setWidth(double w) { width = w; }
    void setLength(double l) { length = l; }
    void setMaxDepth(double d) { maxDepth = d; }

    const String& getName() const { return name; }
    const String& getType() const { return type; }
    double getWidth() const { return width; }
    double getLength() const { return length; }
    double getMaxDepth() const { return maxDepth; }

    void print() const {
        std::cout << "Водойма: " << name.c_str()
            << ", Тип: " << type.c_str()
            << ", Ширина: " << width
            << ", Довжина: " << length
            << ", Макс. глибина: " << maxDepth
            << ", Об'єм: " << calculateVolume()
            << ", Площа: " << calculateSurfaceArea() << "\n";
    }
};

class ReservoirManager {
private:
    int capacity;
    int count;
    Reservoir* reservoirs;

    void resize(int newCapacity) {
        Reservoir* newReservoirs = new Reservoir[newCapacity];
        for (int i = 0; i < count; ++i) {
            newReservoirs[i] = reservoirs[i];
        }
        delete[] reservoirs;
        reservoirs = newReservoirs;
        capacity = newCapacity;
    }

public:
    ReservoirManager(int cap = 2) : capacity(cap), count(0) {
        reservoirs = new Reservoir[capacity];
    }

    ~ReservoirManager() {
        delete[] reservoirs;
    }

    void add(const Reservoir& res) {
        if (count >= capacity) {
            resize(capacity * 2);
        }
        reservoirs[count++] = res;
    }

    void remove(int index) {
        if (index >= 0 && index < count) {
            for (int i = index; i < count - 1; ++i) {
                reservoirs[i] = reservoirs[i + 1];
            }
            count--;
        }
    }

    void print() const {
        std::cout << "Список водойм (" << count << "/" << capacity << "):\n";
        for (int i = 0; i < count; ++i) {
            std::cout << "  [" << i << "] ";
            reservoirs[i].print();
        }
    }
};

int main() {
    ReservoirManager manager(2);

    manager.add(Reservoir("Чорне море", "море", 1000.0, 2000.0, 2210.0));
    manager.add(Reservoir("Азовське море", "море", 340.0, 380.0, 13.5));
    manager.add(Reservoir("Озеро Синевир", "озеро", 0.2, 0.3, 24.0));

    manager.print();

    std::cout << "\n--- Видалення елемента ---\n";
    manager.remove(1);
    manager.print();
}