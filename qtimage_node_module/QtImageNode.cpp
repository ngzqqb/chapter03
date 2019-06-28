#include "QtImageNode.hpp"

namespace sstd {

    void QtImageNodeData::setImage(QImage arg){
        thisImage = std::move( arg );
        thisFlags.set<ImageNodeDataState::ImageChanged>();
    }

       void QtImageNodeData::clearAllChange(){
           thisFlags.clearAll ();
       }

    QtImageNode::QtImageNode(std::shared_ptr<QtImageNodeData> arg) :thisData{std::move(arg)} {

    }

    void QtImageNode::updateTheNode() {

        if(thisData->testChanged<ImageNodeDataState::ImageChanged>()){

        }

        thisData->clearAllChange ();
    }


}/*namespace sstd*/





