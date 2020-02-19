#ifndef LAB11_BIN_MANIP_H_INCLUDED
#define LAB11_BIN_MANIP_H_INCLUDED

#include <iostream>
#include <cstdint>
#include <cstddef>

struct write_le_int32 {
    write_le_int32(std::int32_t _data) : data(_data) {}
    friend std::ostream& operator<<(std::ostream&, const write_le_int32&);
private:
    std::int32_t data;
};

struct read_le_int32 {
    read_le_int32(std::int32_t& _data) : data(_data) {}
    friend std::istream& operator>>(std::istream&, const read_le_int32&);
private:
    std::int32_t& data;
};

struct write_bool {
    write_bool(bool _data) : data(_data) {}
    friend std::ostream& operator<<(std::ostream&, const write_bool&);
private:
    bool data;
};

struct read_bool{
    read_bool(bool& _data) : data(_data) {}
    friend std::istream& operator>>(std::istream&, const read_bool&);
private:
    bool& data;
};

struct write_c_str {
    write_c_str(const std::string _data) : data(_data) {}
    friend std::ostream& operator<<(std::ostream&, const write_c_str&);
private:
    const std::string data;
};

struct read_c_str {
    read_c_str(std::string _data, std::size_t _size) : data(_data), size(_size) {}
    friend std::istream& operator>>(std::istream&, read_c_str&);
private:
    std::string data;
    std::size_t size;
};

#endif

