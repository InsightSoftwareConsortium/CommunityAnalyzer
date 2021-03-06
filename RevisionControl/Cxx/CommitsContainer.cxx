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

#include "CommitsContainer.h"

namespace GitStatistics
{

CommitsContainer::CommitsContainer()
{
}

CommitsContainer::~CommitsContainer()
{
}

CommitsContainer::Iterator
CommitsContainer::Begin()
{
  return this->container.begin();
}

CommitsContainer::ConstIterator
CommitsContainer::Begin() const
{
  return this->container.begin();
}

CommitsContainer::Iterator
CommitsContainer::End()
{
  return this->container.end();
}

CommitsContainer::ConstIterator
CommitsContainer::End() const
{
  return this->container.end();
}

size_t
CommitsContainer::Size() const
{
  return this->container.size();
}

void
CommitsContainer::Add( const Commit & commit )
{
  this->container[commit.GetHash()] = commit;
}

void
CommitsContainer::Print( std::ostream & outputStream ) const
{
  outputStream << "List of Commits" << std::endl;
  outputStream << this->container.size() << " entries" << std::endl;
  outputStream << std::endl;

  for(const auto & entry : this->container )
    {
    entry.second.Print( outputStream );
    outputStream << std::endl;
    }

}

}
