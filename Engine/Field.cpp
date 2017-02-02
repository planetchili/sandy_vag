#include "Field.h"
#include "ContentsImpl.h"

Field::Field()
	:
	tiles( std::make_unique<Tile[]>( width * height ) )
{
	for( int x = 0; x < width; x++ )
	{
		SpawnContents<Rock>( x,0 );
		SpawnContents<Rock>( x,height - 1 );
	}
	for( int y = 0; y < height; y++ )
	{
		SpawnContents<Rock>( 0,y );
		SpawnContents<Rock>( width - 1,y );
	}
}
