#include "Static.hpp"

namespace sstd {

    constexpr const static inline int globalRoundPointPolyGonSize{ 1024 };

    class TheQSGGeometry : public QSGGeometry {
    public:
        inline TheQSGGeometry(int arg) :
            QSGGeometry(defaultAttributes_Point2D(), 2 + arg) {
            auto varPoint = this->vertexDataAsPoint2D();
            const auto varStep = 2 * sstd::toFloat<sstd::constexpr_float_pi, double>() / arg;
            double varAngle = sstd::toFloat<sstd::constexpr_float_pi, double>() / 2;
            varPoint->set(0, 0);
            const auto varFirstPoint = ++varPoint;
            for (int varIndex = 0;
                varIndex < arg;
                ++varIndex, ++varPoint, varAngle -= varStep) {
                varPoint->set(
                    static_cast<GLfloat>(std::cos(varAngle)),
                    static_cast<GLfloat>(std::sin(varAngle)));
            }
            varPoint->set(varFirstPoint->x, varFirstPoint->y);
            this->setDrawingMode(QSGGeometry::DrawTriangleFan);
        }
    private:
        sstd_class(TheQSGGeometry);
    };

    inline static std::shared_ptr< QSGGeometry > createPolygon(int arg) {
        return sstd_make_shared<TheQSGGeometry>(arg);
    }

    Static::Static() : thisCachedQSGGeometry{ 32 } {
        QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
    }

    QObject * Static::instance(QQmlEngine *, QJSEngine *) {
        static Static varAns;
        return &varAns;
    }

    int Static::roundPointPolygonSize() const {
        return globalRoundPointPolyGonSize;
    }

    std::shared_ptr< QSGGeometry > Static::getRoundPolygon() const {
        if (thisRoundPolygon) {
            return thisRoundPolygon;
        }
        thisRoundPolygon = createPolygon(globalRoundPointPolyGonSize);
        return thisRoundPolygon;
    }

    std::shared_ptr< QSGGeometry > Static::getPolygon(int arg) const {
        if (arg < 3) {
            return getRoundPolygon();
        }
        if (arg >= globalRoundPointPolyGonSize) {
            return getRoundPolygon();
        }
        {
            auto varAns = thisCachedQSGGeometry.get(arg);
            if (varAns) {
                return *varAns;
            }
        }
        auto varAns = createPolygon(arg);
        thisCachedQSGGeometry.insert(arg, varAns);
        return varAns;
    }

}/*namespace sstd*/

