#include <iostream>
#include <vector>

class Element {
public:
    virtual int calculate_sum() const = 0;
};

class NumberElement : public Element {
private:
    int value;

public:
    NumberElement(int val) : value(val) {}

    int calculate_sum() const override {
        return value;
    }
};

class ListElement : public Element {
private:
    std::vector<Element*> elements;

public:
    void add_element(Element* elem) {
        elements.push_back(elem);
    }

    int calculate_sum() const override {
        int sum = 0;
        for (const auto& elem : elements) {
            sum += elem->calculate_sum();
        }
        return sum;
    }
};

int main() {
    NumberElement num1(2);
    NumberElement num2(36);
    NumberElement num3(4);

    ListElement list1;
    list1.add_element(&num1);
    list1.add_element(&num2);

    ListElement list2;
    list2.add_element(&list1);
    list2.add_element(&num3);

    std::cout << "Sum of all elements: " << list2.calculate_sum() << std::endl;

    return 0;
}











