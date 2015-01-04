#ifndef IMAGE_UTIL_HPP
#define IMAGE_UTIL_HPP

#include <wx/bitmap.h>

#include "shared.hpp"

#define THUMBNAIL_WIDTH 64
#define THUMBNAIL_HEIGHT 64

class ImageInfo
{
    public:
        ImageInfo(const std::string& filename);
        ~ImageInfo() {}
        const std::string& GetName() const {return name;}
        void SetName(const std::string& new_name) {name = new_name;}
        unsigned int GetWidth() const {return width;}
        void SetWidth(unsigned int new_width) {width = new_width;}
        unsigned int GetHeight() const {return height;}
        void SetHeight(unsigned int new_height) {height = new_height;}
        const wxBitmap& GetThumbnail() const {return thumbnail;}
        bool IsAnimated() const {return images.size() > 1;}
        unsigned int GetFrameCount() const {return images.size();}
        const std::vector<Magick::Image>& GetImages() const {return images;}
    private:
        std::string filename;
        std::string name;
        unsigned int width, height;
        wxBitmap thumbnail;
        std::vector<Magick::Image> images;
};

wxBitmap MagickToBitmap(Magick::Image, int width, int height);

#endif