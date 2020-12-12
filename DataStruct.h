// DataStruct.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include "DLine.h"

template <class data>
class DataStruct {
public:
    virtual bool append(data p) = 0;
    virtual data pop() = 0;
    virtual bool is_empty() = 0;
    virtual bool is_present(data p) = 0;
    virtual size_t find(data p) = 0;
    virtual bool remove(data p) = 0;
    virtual vector<data> find_all(data p1, data p2) = 0;
};


// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
