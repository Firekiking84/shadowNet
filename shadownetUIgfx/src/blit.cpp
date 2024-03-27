#include		"draw.hh"

static void             init_struct(const t_bunny_position      *pos,
                                    t_blit                      *blit,
                                    const t_bunny_pixelarray    *src)
{
  t_bunny_accurate_position     scale;

  if (!pos)
    {
      blit->shift.x = 0;
      blit->shift.y = 0;
    }
  else
    {
      blit->shift.x = pos->x;
      blit->shift.y = pos->y;
    }
  if (src->clipable.scale.x < 0)
    {
      blit->is_x_reverse = true;
      scale.x = src->clipable.scale.x * -1;
    }
  else
    {
      blit->is_x_reverse = false;
      scale.x = src->clipable.scale.x;
    }
  if (src->clipable.scale.y < 0)
    {
      blit->is_y_reverse = true;
      scale.y = src->clipable.scale.y * -1;
    }
  else
    {
      blit->is_y_reverse = false;
      scale.y = src->clipable.scale.y;
    }
  blit->size_dest.x = (src->clipable.clip_width * scale.x);
  blit->size_dest.y = (src->clipable.clip_height * scale.y);
  blit->src_limit = src->clipable.clip_height * src->clipable.clip_width;
  if (blit->is_x_reverse)
    blit->target_pos.x = blit->size_dest.x;
  else
    blit->target_pos.x = 0;
  if (blit->is_y_reverse)
    blit->target_pos.y = blit->size_dest.y;
  else
    blit->target_pos.y = 0;
}

static bool             set_is_end(bool                         is_reverse,
                                   int                          *target_var,
                                   int                          size_dest)
{
  if (is_reverse)
    {
      *target_var -= 1;
      if (*target_var < 0)
        {
          *target_var = size_dest;
          return(true);
        }
    }
  else
    {
      *target_var += 1;
      if (*target_var >= size_dest)
        {
          *target_var = 0;
          return(true);
        }
    }
  return(false);
}

void                    win_blit(t_bunny_pixelarray             *target,
                                 const t_bunny_pixelarray       *src,
                                 const t_bunny_position         *pos)
{
  t_blit                blit;
  float                 ratio;
  unsigned int          *tab;
  int                   npos;
  bool                  y_is_end;
  bool                  x_is_end;

  init_struct(pos, &blit, src);
  tab = src->pixels;
  y_is_end = false;
  while (!y_is_end)//blit.target_pos.y < blit.size_dest.y || target_pos.y > 0
    {
      ratio = win_get_ratio(0, blit.size_dest.y, blit.target_pos.y);
      if (blit.is_y_reverse)
        ratio = 1 - ratio;
      blit.src_pos.y = win_get_value(0, src->clipable.clip_height, ratio);
      blit.src_pos.y += src->clipable.clip_y_position;
      x_is_end = false;
      while (!x_is_end)//blit.target_pos.x < blit.size_dest.x || target_pos.x > 0
        {
          ratio = win_get_ratio(0, blit.size_dest.x, blit.target_pos.x);
          if (blit.is_x_reverse)
            ratio = 1 - ratio;
          blit.src_pos.x = win_get_value(0, src->clipable.clip_width, ratio);
          blit.src_pos.x += src->clipable.clip_x_position;
          npos = win_get_npos(src->clipable.buffer.width, blit.src_pos);
          blit.final_pos.x = blit.target_pos.x + blit.shift.x;
          blit.final_pos.y = blit.target_pos.y + blit.shift.y;
          win_set_pixel(target, &blit.final_pos, tab[npos]);
          x_is_end = set_is_end(blit.is_x_reverse, &blit.target_pos.x, blit.size_dest.x);
        }
      y_is_end = set_is_end(blit.is_y_reverse, &blit.target_pos.y, blit.size_dest.y);
    }
}

