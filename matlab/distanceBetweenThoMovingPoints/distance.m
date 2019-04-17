syms x1 v1x x2 v2x y1 v1y y2 v2y
syms t

dist = sqrt((x1 + v1x * t - x2 - v2x * t)^2 - (y1 + v1y * t - y2 - v2y * t)^2)

minDistTime = solve(diff(dist, t), t, 'ReturnConditions', true)


% минимум расстояния между двумя точками при постоянном движении
% -(2*(v1x - v2x)*(x1 - x2) - 2*(v1y - v2y)*(y1 - y2))/(2*(v1x - v2x)^2 - 2*(v1y - v2y)^2) = minDistTime.t