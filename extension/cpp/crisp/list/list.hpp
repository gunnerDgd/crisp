extern "C"
{
#include <list/list.h>
#include <list/list_iterate.h>
}

#include <memory>

namespace crisp {
	template <typename T, typename Allocator = std::allocator<T>>
 	class list {
	public:
		class iterator;
		class const_iterator;

		class reverse_iterator;
		class const_reverse_iterator;

	public:
		using value_type	  = T;
		using allocator_type  = Allocator;
		
		using size_type		  = std::size_t;
		using difference_type = std::ptrdiff_t;
		
		using reference		  = value_type&;
		using const_reference = const value_type&;

		using pointer		  = typename allocator_type::pointer;
		using const_pointer   = typename allocator_type::const_pointer;

	public:
		explicit list(size_type, const_reference, const allocator_type& = allocator_type());
		explicit list(size_type);
		explicit list(size_type, const allocator_type& = allocator_type());

		template <typename InputIt>
		list(InputIt, InputIt, const allocator_type & = allocator_type());
		list();
		
		list(const list&);
		list(const list&, const allocator_type&);

		list(list&&);
		list(list&&, const allocator_type&);
		list(std::initializer_list<T>, const allocator_type & = allocator_type());

	public:

	};
}