#pragma once
/*
 *      Copyright (C) 2013 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#include "JNIBase.h"

class CJNIURI;
class CJNIIntent : public CJNIBase
{
public:
  CJNIIntent(const std::string &action = "");
  ~CJNIIntent(){};
  CJNIIntent(const jni::jhobject &intent) : CJNIBase(intent){};

  std::string getAction();
  std::string getDataString();
  std::string getPackage();
  std::string getType();

  int getIntExtra(const std::string &name, int defaultValue);

  bool hasExtra(const std::string &name);
  bool hasCategory(const std::string &category);

  void addFlags(int flags);
  void addCategory(const std::string &category);
  void setFlags(int flags);
  void setAction(const std::string &action);
  void setClassName(const std::string &packageName, const std::string &className);

  // Note that these are strings. We auto-convert to uri objects.
  void setDataAndType(const CJNIURI &uri, const std::string &type);
  void setData(const std::string &uri);

  void setPackage(const std::string &packageName);
  void setType(const std::string &type);
};
