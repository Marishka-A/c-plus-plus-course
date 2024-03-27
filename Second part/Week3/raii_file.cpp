#include <iostream>
#include <string>

class File
{
public:
    File(const std::string& filename, const std::string& mode) :
        m_file(fopen(filename.c_str(), mode.c_str())),
        m_isOpen(m_file)
    {
        std::cout << "File" << std::endl;
    }

    File(const File&) = delete;
    File& operator=(const File&) = delete;

    void Write(const std::string& message)
    {
        fputs(message.c_str(), m_file);
    }

    explicit operator bool() const
    {
        return m_isOpen;
    }

    bool IsOpen() const
    {
        return m_isOpen;
    }

    ~File()
    {
        std::cout << "~File" << std::endl;
        fclose(m_file);
    }
private:
    FILE* m_file;
    bool m_isOpen;
};

int main()
{
    // RAII file opener, native ifstream
    File file("data.txt", "w");
    if (file)
    {
        file.Write("Hello world\n");
    }
}
