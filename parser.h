#pragma once
#include <map>
#include <boost/property_tree/ptree.hpp>
#include "core.h"

class AreaLight;
class Material;
class Geom;
class Camera;
class Scene;

class Parser {
  const Scene& scene;
  const boost::property_tree::ptree& attributes;

private:
  template<typename T>
  T getItemFromStorage(
    const std::map<std::string, T>& storage,
    std::string key,
    bool allowNull
  ) const;

  template<typename T>
  std::vector<T> getItemsFromStorage(
    const std::map<std::string, T>& storage,
    std::string key
  ) const;

public:
  Parser(
    const Scene& sc,
    const boost::property_tree::ptree& attr
  );

  std::string getString(std::string key, bool allowEmpty) const;
  float getFloat(std::string key) const;
  int getInt(std::string key) const;
  Vec getVec(std::string key) const;
  Transform getTransform(std::string key) const;
  const AreaLight* getLight(std::string key) const;
  const Material* getMaterial(std::string key) const;
  const Geom* getGeometry(std::string key) const;
  std::vector<const Geom*> getGeometryList(std::string key) const;
};
