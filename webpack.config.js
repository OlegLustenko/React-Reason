const path = require('path');
const webpack = require('webpack');
const HtmlWebpackPlugin = require('html-webpack-plugin');

const resolvePath = fileName => path.resolve(__dirname, 'src', 'assets', fileName);
const appHtml = resolvePath('index.html');

console.log(appHtml);

module.exports = {
  // Entry file can be a Reason or OCaml file
  entry: ['./src/main.re'],
  output: {
    filename: 'out.js',
    path: path.resolve(__dirname, 'dist')
  },
  module: {
    rules: [
      // Set up Reason and OCaml files to use the loader
      {
        test: /\.(re|ml)$/,
        use: 'bs-loader',
        include: path.resolve(__dirname, 'src')
      },
      {
        test: /\.js$/,
        use: 'babel-loader',
        include: path.resolve(__dirname, 'src')
      }
    ]
  },
  plugins: [
    new webpack.HotModuleReplacementPlugin(),
    new HtmlWebpackPlugin({
      inject: true,
      template: appHtml
    })
  ],
  node: {
    dgram: 'empty',
    fs: 'empty',
    net: 'empty',
    tls: 'empty'
  },
  resolve: {
    // Add .re and .ml to the list of extensions webpack recognizes
    extensions: ['.re', '.ml', '.js']
  },
  devServer: {
    hot: true,
    // contentBase: path.resolve(__dirname, 'dist'),
    // quiet: true,
    watchOptions: {
      ignored: /node_modules/
    },
    watchContentBase: true,
    port: 3000,
    publicPath: '/',
    overlay: true,
    // overlay: true,
    // clientLogLevel: 'error',
    // stats: 'errors-only',
    historyApiFallback: {
      // Paths with dots should still use the history fallback.
      // See https://github.com/facebookincubator/create-react-app/issues/387.
      disableDotRule: true
    },
    compress: true
  }
};
