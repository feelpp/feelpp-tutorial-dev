#include <feel/feelcore/environment.hpp>
#include "ut.hpp"

//  Just for information "ut.hpp" file is missing. Do not forget to install the lib boots
//
// https://github.com/boost-ext/ut/tree/master



int main( int argc, char* argv[] )
{
    using namespace Feel;
    
    Environment env( _argc=argc, _argv=argv,
                     _about=about( _name="env",
                                   _author="Feel++ Consortium",
                                   _email="feelpp-devel@feelpp.org") );
    Feel::cout << "proc " << Environment::rank()
              <<" of "<< Environment::numberOfProcessors()
              << std::endl;

    using namespace boost::ut;
    "Environment"_test  = [&] {
        mpi::communicator world;
        expect( Environment::rank() == world.rank() );
        expect( Environment::numberOfProcessors() == world.size() );
    };

}

