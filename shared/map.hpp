#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <vector>

#include "image.hpp"
#include "scene.hpp"

class Image16Bpp;
class Tileset;

/** Class representing a map can be 4 or 8 bpp
  * Maps can only be 256x256 512x256 256x512 or 512x512
  * Affine map can only be 128x128, 256x256, 512x512, or 1024x1024
  */
class Map : public Image
{
    public:
        Map(const Image16Bpp& image, int bpp, bool affine);
        Map(const Image16Bpp& image, std::shared_ptr<Tileset>& global_tileset, bool affine);
        void WriteData(std::ostream& file) const;
        void WriteCommonExport(std::ostream& file) const;
        void WriteExport(std::ostream& file) const;
        std::vector<unsigned short> data;
        std::shared_ptr<Tileset> tileset;
    private:
        void Init4bpp(const Image16Bpp& image);
        void Init8bpp(const Image16Bpp& image);
        void WriteSbbData(std::ostream& file) const;
        void WriteAffineData(std::ostream& file) const;
        bool export_shared_info;
        bool affine;
};

/** Class representing a set of maps which use the same shared Tileset */
class MapScene : public Scene
{
    public:
        MapScene(const std::vector<Image16Bpp>& images, const std::string& name, int bpp, bool affine);
        MapScene(const std::vector<Image16Bpp>& images, const std::string& name, std::shared_ptr<Tileset>& tileset, bool affine);
        const Map& GetMap(int index) const;
        void WriteData(std::ostream& file) const;
        void WriteExport(std::ostream& file) const;
        std::shared_ptr<Tileset> tileset;
};

#endif
