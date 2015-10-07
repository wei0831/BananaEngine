/******************************************************************************/
/*!
\file   FilePath.h
\author Jack Chang
\date   10/06/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#pragma once

namespace BananaEngine
{
  class FilePath
  {
  public:
    FilePath();
    FilePath(std::string file);
    FilePath& operator=(std::string file);
    void SetFilePath(std::string file);
    std::string GetFilePathWithNewExtension(const std::string& newExtension);

    std::string Extension;
    std::string FileName;
    std::string FullDirectory;
    std::string FullPath;
  };
}
