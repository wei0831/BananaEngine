/******************************************************************************/
/*!
\file   FilePath.cpp
\author Jack Chang
\date   10/06/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#include "Precompiled.h"
#include "FilePath.h"

namespace
{
  char convertCharacters(char d)
  {
    if (d == '/')
      return '\\';
    else
      return tolower(d);
  }

  inline void toLower(std::string &s)
  {
    std::transform(s.begin(), s.end(), s.begin(), convertCharacters);
  }
}

namespace BananaEngine
{
  FilePath::FilePath()
  {}

  FilePath::FilePath(std::string file)
  {
    SetFilePath(file);
  }

  FilePath& FilePath::operator=(std::string file)
  {
    SetFilePath(file);
    return *this;
  }

  void FilePath::SetFilePath(std::string file)
  {
    toLower(file);

    FullPath = file;

    std::size_t dirEnd = file.find_last_of("\\/");
    dirEnd = (dirEnd == std::string::npos) ? 0 : dirEnd + 1;

    std::size_t fileEnd = file.find_last_of(".");
    fileEnd = (fileEnd == std::string::npos) ? file.size() : fileEnd;

    //Extension may be nothing
    Extension = file.substr(fileEnd);
    FileName = file.substr(dirEnd, fileEnd - dirEnd);
    FullDirectory = file.substr(0, dirEnd);
  }

  std::string FilePath::GetFilePathWithNewExtension(const std::string& newExtension)
  {
    return FullDirectory + FileName + newExtension;
  }
}
