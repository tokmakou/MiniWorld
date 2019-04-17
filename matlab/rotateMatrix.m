function m = rotateCovarianceMatrix(matrixForRotate, alpha)

m1 = [cos(alpha) sin(alpha);
    -sin(alpha) cos(alpha)];

m3 = [cos(alpha) -sin(alpha);
    sin(alpha) cos(alpha)];

m = m1*matrixForRotate*m3;
