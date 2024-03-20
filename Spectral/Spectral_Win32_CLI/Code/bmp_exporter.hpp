#pragma once

#include "spectral/bitmap.hpp"

#include <filesystem>
#include <memory>

class Bmp_Exporter
{
public:
	explicit Bmp_Exporter(const std::shared_ptr<Spectral::Bitmap> bitmap);

public:
	void write_to_file(const std::filesystem::path& path);
	void import_file(const std::filesystem::path& path);

private:
	const std::shared_ptr<Spectral::Bitmap> m_bitmap;
};