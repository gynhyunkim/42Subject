#include "./minilibx/mlx.h"
#include <stdlib.h>

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;

	int		color[3];
}	t_mlx;

t_mlx	app;

#include <stdio.h>

int		main()
{
	const int	image_width = 256;
	const int	image_height = 256;

	app.mlx_ptr = mlx_init(); //내 소프트웨어와 디스플레이 연결
	//연결 실패시 null, 성공시 non-null pointer 반환(connection identifier)
	app.win_ptr = mlx_new_window(app.mlx_ptr, 700, 400, "rainbow");
	//새 창을 스크린데 띄움
	app.img_ptr = mlx_new_image(app.mlx_ptr, image_width, image_height);
	//새 이미지를 메모리에 생성시킴 
	//이미지 식별자 반환
	app.data = (int *)mlx_get_data_addr(app.img_ptr, &app.bpp, &app.size_l, &app.endian);
	//생성된 이미지에 대한 정보를 반환하여 사용자가 나중에 이미지를 수정할 수 있도록 함
	//첫번째는 이미지 식별자, 픽셀 색상, 이미지 한 줄을 메모리에 저장하는 데 사용되는 바이트 수, 이미지의 픽셀 색상을
	//리틀 엔디안 혹은 빅 엔디안으로 저장하는지 알려줌 -> macOS에서는 클라이언트와 그래픽 프레임워크가 동일한 엔디언을 가짐
	
	int	j = 0;
	while (j < image_height)
	{
		int	i = 0;
		while (i < image_width)
		{
			float	r = (double)i / (image_width - 1);
			float	g = (image_height - (double)j - 1) / (image_height - 1);
			float	b = 0.25;

			int		ir = 255.999 * r;
			int		ig = 255.999 * g;
			int		ib = 255.999 * b;

			app.color[0] = ir * 256 * 256;
			app.color[1] = ig * 256;
			app.color[2] = ib;

			int	color = app.color[0] + app.color[1] + app.color[2];
			app.data[j * 256 + i] = mlx_get_color_value(app.mlx_ptr, color);
			++i;
		}
		j++;
	}
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	mlx_loop(app.mlx_ptr); //이벤트 제어 함수, 키보드와 마우스 이벤트 처리
	//인자로 connection identifier가 필요하므로 mlx_init()의 반환값을 인자로 넘김
}
