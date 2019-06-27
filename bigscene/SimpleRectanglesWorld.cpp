#include "SimpleRectanglesWorld.hpp"

namespace sstd{

    class SimpleRectanglesWorld::SimpleRectanglesWorldData{
    public:
        private:
        int width ;
        int height ;
    private:
        sstd_class (SimpleRectanglesWorldData);
    };

    SimpleRectanglesWorld::SimpleRectanglesWorld(){

    }

    void SimpleRectanglesWorld::updateViewWidth(int){

    }

    void SimpleRectanglesWorld::updateViewHeight(int){

    }

    void SimpleRectanglesWorld::updateViewX(int){

    }

    void SimpleRectanglesWorld::updateViewY(int){

    }

}/*namespace sstd*/

inline static void registerThis(){

}
Q_COREAPP_STARTUP_FUNCTION(registerThis)










