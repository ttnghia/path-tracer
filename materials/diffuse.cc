#include "diffuse.h"

materials::diffuse::diffuse(vec c) : material(), color(c) {}

lightray materials::diffuse::propagate(
  const lightray& incoming,
  intersection& isect,
  randomness& rng
) const {
  vec reflectVector = isect.uniformSampleHemisphere(rng);

  return lightray(
    isect.position + reflectVector * 0.01f,
    reflectVector,
    incoming.color * color
  );
}
