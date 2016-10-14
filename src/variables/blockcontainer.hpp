/*
 * blockcontainer.hpp
 *
 *  Created on: 14 Sep 2016
 *  Author: Holger Schmitz
 */

#ifndef SCHNEK_BLOCKCONTAINER_HPP_
#define SCHNEK_BLOCKCONTAINER_HPP_

#include "block.hpp"

#include <boost/range.hpp>

#include <list>

namespace schnek
{

template<class BlockType>
class ChildBlock;

template<class ChildType>
class BlockContainer
{
  friend ChildBlock<ChildType>;
  private:
    std::list<ChildType*> children;

    void addChild(ChildType *child)
    {
      children.push_back(child);
    }
  protected:
    typedef boost::iterator_range<typename std::list<ChildType*>::const_iterator> child_iterator_range;
    child_iterator_range childBlocks()
    {
      return child_iterator_range(children.begin(), children.end());
    }

    size_t numChildren()
    {
      return children.size();
    }

};

template<class BlockType>
class ChildBlock : public schnek::Block
{
  protected:
    void preInit()
    {
      schnek::Block *pParent = getParent().get();
      BlockContainer<BlockType>* parent = dynamic_cast<BlockContainer<BlockType> *>(getParent().get());
      BlockType *self = dynamic_cast<BlockType *>(this);
      if (parent && self) parent->addChild(self);
    }
};

} // namespace

#endif // SCHNEK_BLOCKCONTAINER_HPP_
