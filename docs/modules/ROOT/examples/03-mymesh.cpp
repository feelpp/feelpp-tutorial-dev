#include <feel/feelcore/environment.hpp>
#include <feel/feelfilters/loadmesh.hpp>
#include <feel/feelvf/integrate.hpp>
#include <feel/feelvf/cst.hpp>

int main( int argc, char** argv )
{
    using namespace Feel;
    
    // initialize Feel++ Environment
    Environment env( _argc=argc, _argv=argv,
                     _about=about( _name="mymesh" ,
                                   _author="Feel++ Consortium",
                                   _email="feelpp-devel@feelpp.org" ) );
   
                                   
    // tag::mesh[]
    // create a mesh with GMSH using Feel++ geometry tool
    auto mesh = loadMesh(_mesh=new  Mesh<Simplex<2>>);
    // end::mesh[]

    LOG(INFO) << "mesh " << soption(_name="gmsh.filename") << " loaded";
    using namespace Feel::vf;
    auto I1 = integrate( _range=elements( mesh ), _expr=cst( 1. ) ).evaluate();
    LOG(INFO) << "volume =" << I1;
    auto I2 = integrate( _range=boundaryfaces( mesh ), _expr=cst( 1. ) ).evaluate();
    LOG(INFO) << "surface = " << I2;
}
