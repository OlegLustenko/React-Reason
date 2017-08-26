type status =
  | Success
  | Error;

type user = {
  _id: string,
  name: string,
  email: string
};

type messageLogin = {
  token: string,
  user
};

type apiLogin = {
  status,
  message: messageLogin
};

type body = {
  user: string,
  password: string
};