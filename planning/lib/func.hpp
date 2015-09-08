#pragma once
#include <cmath>

using std::max;
using std::abs;
using std::hypot;

namespace search
{
    template<typename Node>
    inline auto dy(Node const& node) -> Size
    {
        return abs(node.goal().y - node.coordinate().y);
    }
    template<typename Node>
    inline auto dx(Node const& node) -> Size
    {
        return abs(node.goal().x - node.coordinate().x);
    }

    template<typename Node> 
    struct Heuristc{};

    template<typename Node>
    struct ManhattanDistance : public Heuristc<Node>
    {
        auto operator()(Node const& node) const -> Size
        {
            return max(dy(node), dx(node));
        }
    }

    template<typename Node>
    struct EuclideanDinstance : public Heuristc<Node>
    {
        auto operator()(Node const& node) const -> Size
        {
            return static_cast<Size>(hypot(dy(node), dx(node)));
        }
    }
}//end of namespace