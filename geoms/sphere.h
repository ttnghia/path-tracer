#pragma once
#include "../geom.h"

namespace geoms {

  class sphere : public geom {
  public:
    const vec origin;
    const float radius;

    sphere(material* m, vec o = vec(0), float r = 1.0f);

    virtual intersection intersect(const ray& r) const;
    virtual bbox bounds() const;
  };

}
