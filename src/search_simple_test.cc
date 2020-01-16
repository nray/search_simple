/*
This file is part of the Ristra portage project.
Please see the license file at the root of this repository, or at:
    https://github.com/laristra/portage/blob/master/LICENSE
*/

#include <iostream>


// portage includes
#include "search_simple.h"

// wonton includes
#include "simple_mesh.h"
#include "simple_mesh_wrapper.h"
#include "Point.h"

int main(int argc, char* argv[]) {
  Wonton::Simple_Mesh sm{0, 0, 1, 1, 3, 3};
  Wonton::Simple_Mesh tm{0, 0, 1, 1, 2, 2};
  const Wonton::Simple_Mesh_Wrapper source_mesh_wrapper(sm);
  const Wonton::Simple_Mesh_Wrapper target_mesh_wrapper(tm);

  Portage::SearchSimple<Wonton::Simple_Mesh_Wrapper,
                        Wonton::Simple_Mesh_Wrapper>
      search(source_mesh_wrapper, target_mesh_wrapper);

  for (int tc = 0; tc < 4; ++tc) {
    std::vector<int> candidates;
    search(tc, &candidates);

    if (candidates.size() != 4)
      std::cout<<"Incorrect number of search candidates"<<std::endl;

    // there should be four candidate source cells, in a square
    // compute scbase = index of lower left source cell
    const int tx = tc % 2;
    const int ty = tc / 2;
    const int scbase = tx + ty * 3;
    if (candidates[0] != scbase)
      std::cout<<"Incorrect candidate 0"<<std::endl;
    if (candidates[1] != scbase+1)
      std::cout<<"Incorrect candidate 1"<<std::endl;
    if (candidates[2] != scbase+3)
      std::cout<<"Incorrect candidate 2"<<std::endl;
    if (candidates[3] != scbase+4)
      std::cout<<"Incorrect candidate 3"<<std::endl;
  }
  std::cout<<"Search completed"<<std::endl; 
}  

