#include <iostream>
#include <vector>
using namespace std;

class Container
{
public:
	Container() {}
	~Container() 
	{
		for ( auto data : m_Container )
		{
			if ( data != nullptr )
				delete data;
		}
	}

	void Print() const
	{
		cout << "[ ";
		for ( auto data : m_Container )
		{
			cout << *data << " ";
		}
		cout << "]" << endl;
	}

	bool PushLevel( int* data )
	{
		if ( data == nullptr ) __debugbreak();

		auto findData = FindData( data );
		if ( findData == m_Container.end() )
		{
			m_Container.emplace( m_Container.begin() + m_InsertIndex, data );
			m_InsertIndex++;
			cout << "Push Level = ";
			Print();
			return true;
		}
		return false;
	}

	bool PushOverlay( int* data )
	{
		if ( data == nullptr ) __debugbreak();

		auto findData = FindData( data );
		if ( findData == m_Container.end() )
		{
			m_Container.push_back( data );
			cout << "Push Overl = ";
			Print();
			return true;
		}
		return false;
	}

	bool PopLevel( int* data )
	{
		if ( data == nullptr ) __debugbreak();

		auto findData = FindData( data );
		if ( findData != m_Container.end() )
		{
			m_Container.erase( findData );
			m_InsertIndex--;
			cout << "Pop Level  = "; 
			Print();
			return true;
		}
		return false;
	}

	bool PopOverlay( int* data )
	{
		if ( data == nullptr ) __debugbreak();

		auto findData = FindData( data );
		if ( findData != m_Container.end() )
		{
			m_Container.erase( findData );
			cout << "Pop Overl  = ";
			Print();
			return true;
		}
		return false;
	}
	
	vector<int*>::iterator FindData( int* data )
	{
		return find_if( m_Container.begin(), m_Container.end(),
						[data]( int* target ) {
							return data == target;
						} );
	}
private:
	vector<int*> m_Container;
	unsigned int m_InsertIndex = 0;
};


int main( void )
{
	Container container;

	int* a = new int( 1 ); container.PushLevel( a );
	int* b = new int( 1 ); container.PushLevel( b );
	int* c = new int( 0 ); container.PushOverlay( c );
	int* d = new int( 1 ); container.PushLevel( d );
	int* e = new int( 0 ); container.PushOverlay( e );

	container.PopLevel( d );
	container.PopLevel( b );
	container.PopLevel( a );
	container.PopOverlay( c );
	container.PopOverlay( e );

	return 0;
}