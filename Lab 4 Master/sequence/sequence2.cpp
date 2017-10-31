#include "sequence2.h"
#include <algorithm>
#include <cassert>

namespace main_savitch_4
{

  sequence::sequence(size_type initial_capacity)
  {
    data = new value_type[initial_capacity];
    used = 0;
    capacity = initial_capacity;
    current_index = 0;
  }
  
  sequence::sequence(const sequence& source)
  {
    data = new value_type[source.capacity];
    std::copy (source.data, source.data + source.used, data);
    used = source.used;
    capacity = source.capacity;
    current_index = source.current_index;
  }
  
  sequence::~sequence( )
  {
    delete [] data;
  }
  
  void sequence::resize(size_type new_capacity)
  {
    if (new_capacity < used)
      new_capacity = used;
    if (capacity != new_capacity)
    {
      value_type* temp = new value_type[new_capacity];
      std::copy (data, data + used, temp);
      delete [] data;
      data = temp;
      capacity = new_capacity;
    }
  }
  
  void sequence::start( )
  {
    current_index = 0;
  }
  
  void sequence::advance( )
  {
    assert (is_item());
    ++current_index;
  }
  
  void sequence::insert(const value_type& entry)
  {
    if (size() == capacity)
      resize (2 * capacity);
    if (!is_item())
      current_index = 0;
    for (size_type i = used; i > current_index; --i)
      data[i] = data[i-1];
    data[current_index] = entry;
    ++used;
  }
  
  void sequence::attach(const value_type& entry)
  {
    if (size() == capacity)
      resize (2 * capacity);
    if (used == 0)
    {
      current_index = 0;
      data[current_index] = entry;
    }
    else
    {
      if (!is_item())
	current_index = used - 1;
      for (size_type i = used; i > current_index + 1; --i)
	data[i] = data[i-1];
      current_index++;
      data[current_index] = entry;
    }
    ++used;
  }
  
  void sequence::remove_current( )
  {
    assert (is_item());
    for (size_type i = current_index; i < used - 1; ++i)
      data[i] = data[i+1];
    --used;
  }
  
  void sequence::operator =(const sequence& source)
  {
    if (this != &source)
    {
      if (source.capacity != capacity)
      {
	delete [] data;
	value_type* data = new value_type[source.capacity];
	capacity = source.capacity;
      }
      std::copy (source.data, source.data + source.used, data);
      used = source.used;
      current_index = source.current_index;
    }
  }
  
  sequence::size_type sequence::size( ) const
  {
    return used;
  }
  
  bool sequence::is_item( ) const
  {
    return current_index < used;
  }
  
  sequence::value_type sequence::current( ) const
  {
    assert (is_item());
    return data[current_index];
  }
}  
