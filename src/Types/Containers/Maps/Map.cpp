// #include "Map.hpp"

// size_t Map::Hash(ChimeraObject *item) {
//     size_t total_size = m_map.size() == 0 ? 1 : m_map.size(); 
//     return (item->ToInt() * total_size) % total_size; 
// }

// size_t Map::Size() {
//     size_t sum = 0;

//     for(auto const &item : m_map) {
//         sum += item.size();
//     }

//     return sum;
// }