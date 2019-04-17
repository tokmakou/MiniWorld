syms x1 v1x x2 v2x y1 v1y y2 v2y
syms t
syms r1 r2

distan = sqrt((x1 + v1x * t - x2 - v2x * t)^2 + (y1 + v1y * t - y2 - v2y * t)^2)

minDistTime = solve(diff(distan, t), t, 'ReturnConditions', true)

equalDistanceInTime = solve(distan - r1 - r2, t, 'ReturnConditions', true)

% минимум расстояния между двумя точками при постоянном движении
% minDistTime.t
% ans =
% -(2*(v1x - v2x)*(x1 - x2) + 2*(v1y - v2y)*(y1 - y2))/(2*(v1x - v2x)^2 + 2*(v1y - v2y)^2)
  
% equalDistanceInTime.t
% ans =
%  (v1x*x2 - v1x*x1 + v2x*x1 - v2x*x2 - v1y*y1 + v1y*y2 + v2y*y1 - v2y*y2 + (r1^2*v1x^2 - 2*r1^2*v1x*v2x + r1^2*v2x^2 + r1^2*v1y^2 - 2*r1^2*v1y*v2y + r1^2*v2y^2 + 2*r1*r2*v1x^2 - 4*r1*r2*v1x*v2x + 2*r1*r2*v2x^2 + 2*r1*r2*v1y^2 - 4*r1*r2*v1y*v2y + 2*r1*r2*v2y^2 + r2^2*v1x^2 - 2*r2^2*v1x*v2x + r2^2*v2x^2 + r2^2*v1y^2 - 2*r2^2*v1y*v2y + r2^2*v2y^2 - v1x^2*y1^2 + 2*v1x^2*y1*y2 - v1x^2*y2^2 + 2*v1x*v2x*y1^2 - 4*v1x*v2x*y1*y2 + 2*v1x*v2x*y2^2 + 2*v1x*v1y*x1*y1 - 2*v1x*v1y*x1*y2 - 2*v1x*v1y*x2*y1 + 2*v1x*v1y*x2*y2 - 2*v1x*v2y*x1*y1 + 2*v1x*v2y*x1*y2 + 2*v1x*v2y*x2*y1 - 2*v1x*v2y*x2*y2 - v2x^2*y1^2 + 2*v2x^2*y1*y2 - v2x^2*y2^2 - 2*v2x*v1y*x1*y1 + 2*v2x*v1y*x1*y2 + 2*v2x*v1y*x2*y1 - 2*v2x*v1y*x2*y2 + 2*v2x*v2y*x1*y1 - 2*v2x*v2y*x1*y2 - 2*v2x*v2y*x2*y1 + 2*v2x*v2y*x2*y2 - v1y^2*x1^2 + 2*v1y^2*x1*x2 - v1y^2*x2^2 + 2*v1y*v2y*x1^2 - 4*v1y*v2y*x1*x2 + 2*v1y*v2y*x2^2 - v2y^2*x1^2 + 2*v2y^2*x1*x2 - v2y^2*x2^2)^(1/2))/(v1x^2 - 2*v1x*v2x + v2x^2 + v1y^2 - 2*v1y*v2y + v2y^2)
% -(v1x*x1 - v1x*x2 - v2x*x1 + v2x*x2 + v1y*y1 - v1y*y2 - v2y*y1 + v2y*y2 + (r1^2*v1x^2 - 2*r1^2*v1x*v2x + r1^2*v2x^2 + r1^2*v1y^2 - 2*r1^2*v1y*v2y + r1^2*v2y^2 + 2*r1*r2*v1x^2 - 4*r1*r2*v1x*v2x + 2*r1*r2*v2x^2 + 2*r1*r2*v1y^2 - 4*r1*r2*v1y*v2y + 2*r1*r2*v2y^2 + r2^2*v1x^2 - 2*r2^2*v1x*v2x + r2^2*v2x^2 + r2^2*v1y^2 - 2*r2^2*v1y*v2y + r2^2*v2y^2 - v1x^2*y1^2 + 2*v1x^2*y1*y2 - v1x^2*y2^2 + 2*v1x*v2x*y1^2 - 4*v1x*v2x*y1*y2 + 2*v1x*v2x*y2^2 + 2*v1x*v1y*x1*y1 - 2*v1x*v1y*x1*y2 - 2*v1x*v1y*x2*y1 + 2*v1x*v1y*x2*y2 - 2*v1x*v2y*x1*y1 + 2*v1x*v2y*x1*y2 + 2*v1x*v2y*x2*y1 - 2*v1x*v2y*x2*y2 - v2x^2*y1^2 + 2*v2x^2*y1*y2 - v2x^2*y2^2 - 2*v2x*v1y*x1*y1 + 2*v2x*v1y*x1*y2 + 2*v2x*v1y*x2*y1 - 2*v2x*v1y*x2*y2 + 2*v2x*v2y*x1*y1 - 2*v2x*v2y*x1*y2 - 2*v2x*v2y*x2*y1 + 2*v2x*v2y*x2*y2 - v1y^2*x1^2 + 2*v1y^2*x1*x2 - v1y^2*x2^2 + 2*v1y*v2y*x1^2 - 4*v1y*v2y*x1*x2 + 2*v1y*v2y*x2^2 - v2y^2*x1^2 + 2*v2y^2*x1*x2 - v2y^2*x2^2)^(1/2))/(v1x^2 - 2*v1x*v2x + v2x^2 + v1y^2 - 2*v1y*v2y + v2y^2)

% equalDistanceInTime.conditions
% ans =
%  (v1x - v2x)^2 + (v1y - v2y)^2 ~= 0 & signIm(r1*1i + r2*1i) == 1
%  (v1x - v2x)^2 + (v1y - v2y)^2 ~= 0 & signIm(r1*1i + r2*1i) == 1
 