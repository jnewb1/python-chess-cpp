#include <boost/python.hpp>

#include <Square.h>
#include <Squares.h>

int parse(std::string st)
{
    return 50;
}

BOOST_PYTHON_MODULE(python_chess)
{
    using namespace boost::python;

    for (size_t i = 0; i < SQUARES.size(); i++)
    {
        scope().attr(SQUARES_NAME[i].c_str()) = SQUARES[i];
    }

    def("parse_square", SquareTools::parse);
    def("square_name", SquareTools::name);
    def("square", SquareTools::square);
    def("square_file", SquareTools::file);
    def("square_rank", SquareTools::rank);
    def("square_distance", SquareTools::distance);
    def("square_mirror", SquareTools::mirror);
}