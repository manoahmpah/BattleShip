#ifndef SHIP_H
#define SHIP_H
#include <string>


class Ship {
    public:
        Ship(int idShip, const std::string_view &nameShip, bool isShipHorizontal, int sizeShip, bool isPosed);

        /* =========== Getter =========== */
        [[nodiscard]] std::string getName() const;
        [[nodiscard]] bool getIsHit() const;
        [[nodiscard]] bool getIsSunk() const;
        [[nodiscard]] bool getIsPosed() const;
        [[nodiscard]] int getId() const;
        [[nodiscard]] int getSize() const;
        [[nodiscard]] bool getIsHorizontal() const;

        /* =========== Setter =========== */
        void setIsHit(bool isHit);
        void setIsSunk(bool isSunk);
        void setIsPosed(bool isPosed);
        void setId(int id);
        void setSize(int size);
        void setIsHorizontal(bool isHorizontal);
        void setName(const std::string_view &name);

    private:
        bool operator==(const Ship & ship) const;
        std::string _state;
        std::string _name;
        bool _isHit;
        bool _isSunk;
        bool _isPosed;
        int _id;
        int _size;
        bool _isHorizontal;
};



#endif //SHIP_H
