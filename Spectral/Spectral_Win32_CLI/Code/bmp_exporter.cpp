#include "bmp_exporter.hpp"

#include "spectral/bitmap.hpp"
#include "spectral/core_types.hpp"

#include <filesystem>
#include <fstream>
#include <sstream>

#include <Windows.h>

#pragma pack (push, 2)
struct Bmp_Header
{
	Spectral::Char magic[2]; // This should equal "BM" on windows
	Spectral::U32 size; // File size in bytes
	Spectral::UByte reserved[4];
	Spectral::U32 offset; // offset to start of image.
	BITMAPINFOHEADER dib_header;
};

#pragma pack(pop)

static_assert(offsetof(Bmp_Header, dib_header) == sizeof(BITMAPFILEHEADER), "Fuck");

Bmp_Exporter::Bmp_Exporter(const std::shared_ptr<Spectral::Bitmap> bitmap)
	: m_bitmap(bitmap)
{
}


void Bmp_Exporter::write_to_file(const std::filesystem::path& path)
{
	using namespace Spectral;
	const auto dimensions = m_bitmap->get_size();
	const Sz width = dimensions.x;
	const Sz height = dimensions.y;
	const Sz size_in_bytes = width * height * 3;
	
	Bmp_Header header = {};
	header.magic[0] = 'B';
	header.magic[1] = 'M';
	header.size = (LONG)(width * height * 3 + sizeof(Bmp_Header));
	header.offset = sizeof(Bmp_Header);


	header.dib_header.biSize = sizeof(header.dib_header);
	header.dib_header.biWidth = (LONG)width;
	header.dib_header.biHeight = (LONG)height;
	header.dib_header.biBitCount = 24;
	header.dib_header.biPlanes = 1;
	header.dib_header.biCompression = BI_RGB;
	header.dib_header.biSizeImage = (DWORD)size_in_bytes;

	std::ofstream stream(path, std::ios::binary);
	stream.write((const char*)&header, sizeof(header));
	stream.write((const char*)m_bitmap->get_data_ptr(), size_in_bytes);
}

void Bmp_Exporter::import_file(const std::filesystem::path& path)
{
	const std::ifstream stream(path, std::ios::binary);
	std::stringstream buffer;
	buffer << stream.rdbuf();
	std::string buffer_string = buffer.str();

	Bmp_Header* header = (Bmp_Header*)buffer_string.data();

}
