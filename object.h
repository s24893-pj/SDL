#ifndef OBJECT_H
#define OBJECT_H

class object {
private:
    int rows;
    int cols;

public:
    object();

    void setRows(int rows) {
        this->rows = rows;
    }

    void setCols(int cols) {
        this->cols = cols;
    }

    [[nodiscard]] int getRows() const {
        return rows;
    }

    [[nodiscard]] int getCols() const {
        return cols;
    }
};


#endif
