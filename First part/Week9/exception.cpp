#include <iostream>
#include <vector>
#include <exception>

// f10() <- f9() ... <-f1() <- main()

// main()
// f1
// f2
// ...
// f6
// f10

namespace return_code
{
    int DivNum(const int lhs, const int rhs, int& res)
    {
        if (rhs == 0)
        {
            return 1;
        }
        res = lhs / rhs;
        return 0;
    }
}

namespace return_res
{
    int DivNum(const int lhs, const int rhs, int& ret)
    {
        if (rhs == 0)
        {
            ret = -1;
            return 1;
        }
        return lhs / rhs;
    }
}

namespace bad_impl
{
    int DivNum(const int lhs, const int rhs)
    {
        return lhs / rhs;
    }
} // namespace bad_impl

namespace good_impl
{
    int DivNum(const int lhs, const int rhs)
    {
        if (rhs == 0)
        {
            throw std::runtime_error("rhs = 0");
        }
        return lhs / rhs;
    }
} // namespace good_impl


int main()
{
    //DivNum(10, 0);
    // return error code
    {
        int res;
        int ret = return_code::DivNum(10, 0, res);
        if (ret > 0)
        {
            std::cout << "rhs = 0" << std::endl;
        }
        else
        {
            std::cout << res << std::endl;
        }
    }
    // return res
    {
    }
    // god impl
    {
        //int res = good_impl::DivNum(10, 0);
        try
        {
            int res = good_impl::DivNum(10, 0);
        }
        catch (const std::runtime_error& e)
        {
            std::cout << e.what() << '\n';
        }
        catch (const std::logic_error& e)
        {
            std::cout << e.what() << '\n';
        }
        catch (const std::exception& e)
        {

        }
        catch (...)
        {

        }
    }
    // bad impl
    {
        try
        {
            //bad_impl::DivNum(10, 0);
        }
        catch (...)
        {
            std::cout << "rhs = 0" << std::endl;
        }
    }
    // std::vector
    {
        std::vector<int> vec = {1, 2, 3};
        //int res = vec[2374673248]; // UB
        try
        {
            int res = vec.at(2374673248);
        }
        catch (const std::out_of_range& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
    }
    return 0;
}