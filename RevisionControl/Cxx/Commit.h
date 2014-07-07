/*=========================================================================
 *
 *  Copyright Kitware
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef __Commit_h
#define __Commit_h

#include <string>
#include <unordered_map>

#include "Date.h"
#include "Person.h"
#include "FileChange.h"

namespace GitStatistics
{

class Commit
{
public:
  Commit();
  ~Commit();

  Commit( const Commit & otherCommit );

  const std::string & GetHash() const;

  const Person & GetAuthor() const;

  const Person & GetCommitter() const;

  const Date & GetDate() const;

  void SetHash( const std::string & hashvalue );

  void SetAuthor( const std::string & authorname );

  void SetCommitter( const std::string & committername );

  void SetDate( const std::string & datestring );

  typedef FileChange::NumberOfLinesType  NumberOfLinesType;

  void AddFileChange( NumberOfLinesType linesAdded, NumberOfLinesType linesRemoved, const std::string & filechangestring );

  NumberOfLinesType GetNumberOfLinesAdded() const;

  NumberOfLinesType GetNumberOfLinesRemoved() const;

  void Print( std::ostream & os ) const;

private:

  typedef std::unordered_map< std::string, FileChange >  FileChangesContainer;

  std::string           hash;
  Date                  date;
  Person                author;
  Person                committer;
  FileChangesContainer  fileChanges;

};

}

#endif
