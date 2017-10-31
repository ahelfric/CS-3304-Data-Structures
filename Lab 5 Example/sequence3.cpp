#include "sequence3.h"
#include <cassert>

namespace main_savitch_5
{
  sequence::sequence( )
  {
    head_ptr = NULL;
    tail_ptr = NULL;
    cursor = NULL;
    precursor = NULL;
    many_nodes = 0;
  }

  sequence::sequence(const sequence& source)
  {
    many_nodes = source.many_nodes;
    list_copy (source.head_ptr, head_ptr, tail_ptr);
    if (source.precursor == NULL)
    {
      precursor = NULL;
      cursor = head_ptr;
    }
    else
    {
      size_type count = 1;
      node* temp = source.head_ptr;
      while (source.precursor != temp)
      {
	temp = temp -> link();
	++count;
      }
      precursor = list_locate (head_ptr, count);
      cursor = precursor -> link();
    }
  }
  

  sequence::~sequence( )
  {
    list_clear (head_ptr);
  }

  void sequence::start( )
  {
    precursor = NULL;
    cursor = head_ptr;
  }

  void sequence::advance( )
  {
    assert (is_item());
    precursor = cursor;
    cursor = cursor -> link();
  }

  void sequence::insert(const value_type& entry)
  {
    if (!is_item())
      start();
    if (precursor == NULL)
    {
      list_head_insert (head_ptr, entry);
      cursor = head_ptr;
      if (tail_ptr == NULL)
	tail_ptr = head_ptr;
    }
    else
    {
      list_insert (precursor, entry);
      cursor = precursor -> link();
    }
    ++many_nodes;
  }

  void sequence::attach(const value_type& entry)
  {
    if (!is_item())
      if (precursor == NULL)
      {
	list_head_insert (head_ptr, entry);
	cursor = head_ptr;
	tail_ptr = head_ptr;
      }
      else
      {
	list_insert (precursor, entry);
	cursor = precursor -> link();
	tail_ptr = cursor;
      }
    else
    {
      list_insert (cursor, entry);
      precursor = cursor;
      cursor = cursor -> link();
      if (precursor == tail_ptr)
	tail_ptr = cursor;
    }
    ++many_nodes;
  }

  void sequence::operator =(const sequence& source)
  {
    if (this != &source)
    {
      list_clear (head_ptr);
      tail_ptr = NULL;
      many_nodes = source.many_nodes;
      list_copy (source.head_ptr, head_ptr, tail_ptr);
      if (source.precursor == NULL)
      {
	precursor = NULL;
	cursor = head_ptr;
      }
      else
      {
	size_type count = 1;
	node* temp = source.head_ptr;
	while (source.precursor != temp)
	{
	  temp = temp -> link();
	  ++count;
	}
	precursor = list_locate (head_ptr, count);
	cursor = precursor -> link();
      }      
    }
  }
  
  void sequence::remove_current( )
  {
    assert (is_item());
    if (precursor == NULL)
    {
      list_head_remove(head_ptr);
      cursor = head_ptr;
    }
    else
    {
      list_remove (precursor);
      cursor = precursor -> link();
    }
    --many_nodes;
  }

  sequence::value_type sequence::current( ) const
  {
    assert (is_item());
    return cursor -> data();
  }
 
}
